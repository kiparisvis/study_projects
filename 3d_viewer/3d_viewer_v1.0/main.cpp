#include "main.hpp"
// #include "ui_3dviewer.hpp"

Viewer3d::Viewer3d(QWidget *parent) : QOpenGLWidget(parent) {}

void Viewer3d::load_settings() {
  ifstream file("3dviewer.ini");
  string str;
  if (file.is_open()) {
    file >> str;
    backR = stod(str);
    file >> str;
    backG = stod(str);
    file >> str;
    backB = stod(str);
    file >> str;
    lineR = stod(str);
    file >> str;
    lineG = stod(str);
    file >> str;
    lineB = stod(str);
    file >> str;
    pointR = stod(str);
    file >> str;
    pointG = stod(str);
    file >> str;
    pointB = stod(str);
    file >> str;
    lineWidth = stod(str);
    file >> str;
    pointWidth = stod(str);
    file >> str;
    pointType = stoi(str);
    file >> str;
    parallel = stoi(str);
    file >> str;
    dottedline = stoi(str);
    update();
  }
}

Viewer3d::~Viewer3d() {
  ofstream outfile("3dviewer.ini");
  outfile << setprecision(6);
  outfile << backR << endl;
  outfile << backG << endl;
  outfile << backB << endl;
  outfile << lineR << endl;
  outfile << lineG << endl;
  outfile << lineB << endl;
  outfile << pointR << endl;
  outfile << pointG << endl;
  outfile << pointB << endl;
  outfile << lineWidth << endl;
  outfile << pointWidth << endl;
  outfile << pointType << endl;
  outfile << parallel << endl;
  outfile << dottedline << endl;
  outfile.close();
  free(data.polygons);
  free(data.vertex);
}

void Viewer3d::load_file(QString filename) {
  if (filename != nullptr) {
    if (data.vertex != nullptr) {
      free(data.polygons);
      free(data.vertex);
    }
    if (parse((char *)filename.toStdString().c_str(), &data) != OK)
      perror("Error: ");
    update();
  }
}

void Viewer3d::initializeGL() {
  initializeOpenGLFunctions();
  glEnable(GL_DEPTH_TEST);
  glLoadIdentity();
  glMatrixMode(GL_PROJECTION);
  resize(700, 700);
}
void Viewer3d::paintGL() {
  resize(700, 700);
  glClearColor(backR, backG, backB, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  if (parallel) {
    glFrustum(-1, 1, -1, 1, 2, 12);
    glTranslatef(0, 0, -8);
  } else {
    glOrtho(-1, 1, -1, 1, -1000.0f, 1000.0f);
  }

  glVertexPointer(3, GL_DOUBLE, 0, data.vertex);
  glEnableClientState(GL_VERTEX_ARRAY);
  if (pointType != NONE) {
    glColor3f(pointR, pointG, pointB);
    if (pointType == ROUND) glEnable(GL_POINT_SMOOTH);
    glPointSize(pointWidth);
    glDrawArrays(GL_POINTS, 0, data.vertex_size / 3);
    if (pointType == ROUND) glDisable(GL_POINT_SMOOTH);
  }
  glColor3f(lineR, lineG, lineB);
  if (dottedline) {
    glEnable(GL_LINE_STIPPLE);
    glLineStipple(1, 0x3333);
  }
  glLineWidth(lineWidth);
  glDrawElements(GL_LINES, data.polygon_size, GL_UNSIGNED_INT, data.polygons);
  glDisableClientState(GL_VERTEX_ARRAY);
  if (dottedline) glDisable(GL_LINE_STIPPLE);
  if (glGetError() != 0) std::cout << "ERROR: " << glGetError() << std::endl;
}

void Viewer3d::changePointType(short int type) {
  pointType = type;
  pointG = 1;
  pointWidth = 10;
  update();
}

void Viewer3d::mousePressEvent(QMouseEvent *m) {
  mPos = m->pos();
  if (m->button() == Qt::LeftButton) {
    leftButton = true;
  } else if (m->button() == Qt::RightButton) {
    rightButton = true;
  }
}
void Viewer3d::mouseMoveEvent(QMouseEvent *m) {
  if (leftButton) {
    xRot = (m->pos().y() - mPos.y()) / 10;
    yRot = (m->pos().x() - mPos.x()) / 10;
    rotation_x(&data, xRot);
    rotation_y(&data, yRot);
    update();
  } else if (rightButton) {
    xMov = (m->pos().y() - mPos.y()) / 10000.;
    yMov = (m->pos().x() - mPos.x()) / 10000.;
    xMov *= -1;
    move_x(&data, yMov);
    move_y(&data, xMov);
    update();
  }
}

void Viewer3d::rotate(double xr, double yr, double zr) {
  rotation_x(&data, xr);
  rotation_y(&data, yr);
  rotation_z(&data, zr);
  update();
}

void Viewer3d::changepos_x(double xMov) {
  move_x(&data, xMov);
  update();
}

void Viewer3d::changepos_y(double yMov) {
  move_y(&data, yMov);
  update();
}

void Viewer3d::changepos_z(double zMov) {
  move_z(&data, zMov);
  update();
}

void Viewer3d::setParallel(bool parallel_) {
  parallel = parallel_;
  update();
}

void Viewer3d::setPointWidth(double pw) {
  pointWidth = pw;
  update();
}

void Viewer3d::changePointR(double c) {
  pointR = c;
  update();
}
void Viewer3d::changePointG(double c) {
  pointG = c;
  update();
}
void Viewer3d::changePointB(double c) {
  pointB = c;
  update();
}

void Viewer3d::changeLineR(double c) {
  lineR = c;
  update();
}
void Viewer3d::changeLineG(double c) {
  lineG = c;
  update();
}
void Viewer3d::changeLineB(double c) {
  lineB = c;
  update();
}

void Viewer3d::setLineWidth(double lw) {
  lineWidth = lw;
  update();
}

void Viewer3d::setDottedLine(bool dl) {
  dottedline = dl;
  update();
}

void Viewer3d::mouseReleaseEvent(QMouseEvent *m) {
  leftButton = false;
  rightButton = false;
  m->pos() = mPos;
}

void Viewer3d::zoom_on(double zz) {
  if ((!((zz >= 0) && (zz <= 0))) && (zz >= 0)) scale(&data, zz);
  update();
}

void Viewer3d::wheelEvent(QWheelEvent *m) {
  scaleValue = (m->angleDelta().y() >= 0) ? 1.1 : 0.9;
  scale(&data, scaleValue);
  update();
}
void Viewer3d::changeBackround(double r, double g, double b) {
  backR = r;
  backG = g;
  backB = b;
  update();
}
void Viewer3d::changeBackgroundR(double c) {
  backR = c;
  update();
}
void Viewer3d::changeBackgroundG(double c) {
  backG = c;
  update();
}
void Viewer3d::changeBackgroundB(double c) {
  backB = c;
  update();
}

void Viewer3d::saveBmp(const QString &filename) {
  QOpenGLWidget::grabFramebuffer().save(filename, "bmp");
}
void Viewer3d::saveJpeg(const QString &filename) {
  QOpenGLWidget::grabFramebuffer().save(filename, "jpeg");
}
void Viewer3d::bla() {
  if (time < 55) {
    QImage image;
    image = QOpenGLWidget::grabFramebuffer();
    gif->addFrame(image, 10);
    time++;
  } else {
    gif->save("3dviewer.gif");
    timer->stop();
    delete timer;
    delete gif;
  }
}
void Viewer3d::keyPressEvent(QKeyEvent *m) {
  if (m->key() == Qt::Key_Space) {
    time = 0;
    gif = new QGifImage();
    timer = new QTimer(this);
    gif->setDefaultDelay(100);
    connect(timer, &QTimer::timeout, this, &Viewer3d::bla);
    timer->start(100);
  }
}

void Viewer3d::saveGif() {
  time = 0;
  gif = new QGifImage();
  timer = new QTimer(this);
  gif->setDefaultDelay(100);
  connect(timer, &QTimer::timeout, this, &Viewer3d::bla);
  timer->start(100);
}

int main(int ac, char **av) {
  QApplication a(ac, av);
  MainWindow w;
  w.setup();
  w.show();

  return a.exec();
}
