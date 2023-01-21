#ifndef SRC_S21_STRERROR_H_
#define SRC_S21_STRERROR_H_

#define MAX_MESSAGE 200

#ifdef __linux__

#define ERRMAX 135

#define EPERM 1            /* Operation not permitted */
#define ENOENT 2           /* No such file or directory */
#define ESRCH 3            /* No such process */
#define EINTR 4            /* Interrupted system call */
#define EIO 5              /* I/O error */
#define ENXIO 6            /* No such device or address */
#define E2BIG 7            /* Argument list too long */
#define ENOEXEC 8          /* Exec format error */
#define EBADF 9            /* Bad file number */
#define ECHILD 10          /* No child processes */
#define EAGAIN 11          /* Try again */
#define ENOMEM 12          /* Out of memory */
#define EACCES 13          /* Permission denied */
#define EFAULT 14          /* Bad address */
#define ENOTBLK 15         /* Block device required */
#define EBUSY 16           /* Device or resource busy */
#define EEXIST 17          /* File exists */
#define EXDEV 18           /* Cross-device link */
#define ENODEV 19          /* No such device */
#define ENOTDIR 20         /* Not a directory */
#define EISDIR 21          /* Is a directory */
#define EINVAL 22          /* Invalid argument */
#define ENFILE 23          /* File table overflow */
#define EMFILE 24          /* Too many open files */
#define ENOTTY 25          /* Not a typewriter */
#define ETXTBSY 26         /* Text file busy */
#define EFBIG 27           /* File too large */
#define ENOSPC 28          /* No space left on device */
#define ESPIPE 29          /* Illegal seek */
#define EROFS 30           /* Read-only file system */
#define EMLINK 31          /* Too many links */
#define EPIPE 32           /* Broken pipe */
#define EDOM 33            /* Math argument out of domain of func */
#define ERANGE 34          /* Math result not representable */
#define EDEADLK 35         /* Resource deadlock would occur */
#define ENAMETOOLONG 36    /* File name too long */
#define ENOLCK 37          /* No record locks available */
#define ENOSYS 38          /* Invalid system call number */
#define ENOTEMPTY 39       /* Directory not empty */
#define ELOOP 40           /* Too many symbolic links encountered */
#define EWOULDBLOCK EAGAIN /* Operation would block */
#define ENOMSG 42          /* No message of desired type */
#define EIDRM 43           /* Identifier removed */
#define ECHRNG 44          /* Channel number out of range */
#define EL2NSYNC 45        /* Level 2 not synchronized */
#define EL3HLT 46          /* Level 3 halted */
#define EL3RST 47          /* Level 3 reset */
#define ELNRNG 48          /* Link number out of range */
#define EUNATCH 49         /* Protocol driver not attached */
#define ENOCSI 50          /* No CSI structure available */
#define EL2HLT 51          /* Level 2 halted */
#define EBADE 52           /* Invalid exchange */
#define EBADR 53           /* Invalid request descriptor */
#define EXFULL 54          /* Exchange full */
#define ENOANO 55          /* No anode */
#define EBADRQC 56         /* Invalid request code */
#define EBADSLT 57         /* Invalid slot */
#define EDEADLOCK EDEADLK
#define EBFONT 59           /* Bad font file format */
#define ENOSTR 60           /* Device not a stream */
#define ENODATA 61          /* No data available */
#define ETIME 62            /* Timer expired */
#define ENOSR 63            /* Out of streams resources */
#define ENONET 64           /* Machine is not on the network */
#define ENOPKG 65           /* Package not installed */
#define EREMOTE 66          /* Object is remote */
#define ENOLINK 67          /* Link has been severed */
#define EADV 68             /* Advertise error */
#define ESRMNT 69           /* Srmount error */
#define ECOMM 70            /* Communication error on send */
#define EPROTO 71           /* Protocol error */
#define EMULTIHOP 72        /* Multihop attempted */
#define EDOTDOT 73          /* RFS specific error */
#define EBADMSG 74          /* Not a data message */
#define EOVERFLOW 75        /* Value too large for defined data type */
#define ENOTUNIQ 76         /* Name not unique on network */
#define EBADFD 77           /* File descriptor in bad state */
#define EREMCHG 78          /* Remote address changed */
#define ELIBACC 79          /* Can not access a needed shared library */
#define ELIBBAD 80          /* Accessing a corrupted shared library */
#define ELIBSCN 81          /* .lib section in a.out corrupted */
#define ELIBMAX 82          /* Attempting to link in too many shared libraries */
#define ELIBEXEC 83         /* Cannot exec a shared library directly */
#define EILSEQ 84           /* Illegal byte sequence */
#define ERESTART 85         /* Interrupted system call should be restarted */
#define ESTRPIPE 86         /* Streams pipe error */
#define EUSERS 87           /* Too many users */
#define ENOTSOCK 88         /* Socket operation on non-socket */
#define EDESTADDRREQ 89     /* Destination address required */
#define EMSGSIZE 90         /* Message too long */
#define EPROTOTYPE 91       /* Protocol wrong type for socket */
#define ENOPROTOOPT 92      /* Protocol not available */
#define EPROTONOSUPPORT 93  /* Protocol not supported */
#define ESOCKTNOSUPPORT 94  /* Socket type not supported */
#define EOPNOTSUPP 95       /* Operation not supported on transport endpoint */
#define EPFNOSUPPORT 96     /* Protocol family not supported */
#define EAFNOSUPPORT 97     /* Address family not supported by protocol */
#define EADDRINUSE 98       /* Address already in use */
#define EADDRNOTAVAIL 99    /* Cannot assign requested address */
#define ENETDOWN 100        /* Network is down */
#define ENETUNREACH 101     /* Network is unreachable */
#define ENETRESET 102       /* Network dropped connection because of reset */
#define ECONNABORTED 103    /* Software caused connection abort */
#define ECONNRESET 104      /* Connection reset by peer */
#define ENOBUFS 105         /* No buffer space available */
#define EISCONN 106         /* Transport endpoint is already connected */
#define ENOTCONN 107        /* Transport endpoint is not connected */
#define ESHUTDOWN 108       /* Cannot send after transport endpoint shutdown */
#define ETOOMANYREFS 109    /* Too many references: cannot splice */
#define ETIMEDOUT 110       /* Connection timed out */
#define ECONNREFUSED 111    /* Connection refused */
#define EHOSTDOWN 112       /* Host is down */
#define EHOSTUNREACH 113    /* No route to host */
#define EALREADY 114        /* Operation already in progress */
#define EINPROGRESS 115     /* Operation now in progress */
#define ESTALE 116          /* Stale file handle */
#define EUCLEAN 117         /* Structure needs cleaning */
#define ENOTNAM 118         /* Not a XENIX named type file */
#define ENAVAIL 119         /* No XENIX semaphores available */
#define EISNAM 120          /* Is a named type file */
#define EREMOTEIO 121       /* Remote I/O error */
#define EDQUOT 122          /* Quota exceeded */
#define ENOMEDIUM 123       /* No medium found */
#define EMEDIUMTYPE 124     /* Wrong medium type */
#define ECANCELED 125       /* Operation Canceled */
#define ENOKEY 126          /* Required key not available */
#define EKEYEXPIRED 127     /* Key has expired */
#define EKEYREVOKED 128     /* Key has been revoked */
#define EKEYREJECTED 129    /* Key was rejected by service */
#define EOWNERDEAD 130      /* Owner died */
#define ENOTRECOVERABLE 131 /* State not recoverable */
#define ERFKILL 132         /* Operation not possible due to RF-kill */
#define EHWPOISON 133       /* Memory page has hardware error */

#define ERRORS                                                                                               \
    {                                                                                                        \
        "Success", "Operation not permitted", "No such file or directory", "No such process",                \
            "Interrupted system call", "Input/output error", "No such device or address",                    \
            "Argument list too long", "Exec format error", "Bad file descriptor", "No child processes",      \
            "Resource temporarily unavailable", "Cannot allocate memory", "Permission denied",               \
            "Bad address", "Block device required", "Device or resource busy", "File exists",                \
            "Invalid cross-device link", "No such device", "Not a directory", "Is a directory",              \
            "Invalid argument", "Too many open files in system", "Too many open files",                      \
            "Inappropriate ioctl for device", "Text file busy", "File too large", "No space left on device", \
            "Illegal seek", "Read-only file system", "Too many links", "Broken pipe",                        \
            "Numerical argument out of domain", "Numerical result out of range",                             \
            "Resource deadlock avoided", "File name too long", "No locks available",                         \
            "Function not implemented", "Directory not empty", "Too many levels of symbolic links",          \
            "Unknown error 41", "No message of desired type", "Identifier removed",                          \
            "Channel number out of range", "Level 2 not synchronized", "Level 3 halted", "Level 3 reset",    \
            "Link number out of range", "Protocol driver not attached", "No CSI structure available",        \
            "Level 2 halted", "Invalid exchange", "Invalid request descriptor", "Exchange full", "No anode", \
            "Invalid request code", "Invalid slot", "Unknown error 58", "Bad font file format",              \
            "Device not a stream", "No data available", "Timer expired", "Out of streams resources",         \
            "Machine is not on the network", "Package not installed", "Object is remote",                    \
            "Link has been severed", "Advertise error", "Srmount error", "Communication error on send",      \
            "Protocol error", "Multihop attempted", "RFS specific error", "Bad message",                     \
            "Value too large for defined data type", "Name not unique on network",                           \
            "File descriptor in bad state", "Remote address changed",                                        \
            "Can not access a needed shared library", "Accessing a corrupted shared library",                \
            ".lib section in a.out corrupted", "Attempting to link in too many shared libraries",            \
            "Cannot exec a shared library directly", "Invalid or incomplete multibyte or wide character",    \
            "Interrupted system call should be restarted", "Streams pipe error", "Too many users",           \
            "Socket operation on non-socket", "Destination address required", "Message too long",            \
            "Protocol wrong type for socket", "Protocol not available", "Protocol not supported",            \
            "Socket type not supported", "Operation not supported", "Protocol family not supported",         \
            "Address family not supported by protocol", "Address already in use",                            \
            "Cannot assign requested address", "Network is down", "Network is unreachable",                  \
            "Network dropped connection on reset", "Software caused connection abort",                       \
            "Connection reset by peer", "No buffer space available",                                         \
            "Transport endpoint is already connected", "Transport endpoint is not connected",                \
            "Cannot send after transport endpoint shutdown", "Too many references: cannot splice",           \
            "Connection timed out", "Connection refused", "Host is down", "No route to host",                \
            "Operation already in progress", "Operation now in progress", "Stale file handle",               \
            "Structure needs cleaning", "Not a XENIX named type file", "No XENIX semaphores available",      \
            "Is a named type file", "Remote I/O error", "Disk quota exceeded", "No medium found",            \
            "Wrong medium type", "Operation canceled", "Required key not available", "Key has expired",      \
            "Key has been revoked", "Key was rejected by service", "Owner died", "State not recoverable",    \
            "Operation not possible due to RF-kill", "Memory page has hardware error", "Unknown error",      \
    }

#else  //  MacOS

#define ERRMAX 108

#define EPERM 1             /* Operation not permitted */
#define ENOENT 2            /* No such file or directory */
#define ESRCH 3             /* No such process */
#define EINTR 4             /* Interrupted system call */
#define EIO 5               /* Input/output error */
#define ENXIO 6             /* Device not configured */
#define E2BIG 7             /* Argument list too long */
#define ENOEXEC 8           /* Exec format error */
#define EBADF 9             /* Bad file descriptor */
#define ECHILD 10           /* No child processes */
#define EDEADLK 11          /* Resource deadlock avoided */
#define ENOMEM 12           /* Cannot allocate memory */
#define EACCES 13           /* Permission denied */
#define EFAULT 14           /* Bad address */
#define ENOTBLK 15          /* Block device required */
#define EBUSY 16            /* Device / Resource busy */
#define EEXIST 17           /* File exists */
#define EXDEV 18            /* Cross-device link */
#define ENODEV 19           /* Operation not supported by device */
#define ENOTDIR 20          /* Not a directory */
#define EISDIR 21           /* Is a directory */
#define EINVAL 22           /* Invalid argument */
#define ENFILE 23           /* Too many open files in system */
#define EMFILE 24           /* Too many open files */
#define ENOTTY 25           /* Inappropriate ioctl for device */
#define ETXTBSY 26          /* Text file busy */
#define EFBIG 27            /* File too large */
#define ENOSPC 28           /* No space left on device */
#define ESPIPE 29           /* Illegal seek */
#define EROFS 30            /* Read-only file system */
#define EMLINK 31           /* Too many links */
#define EPIPE 32            /* Broken pipe */
#define EDOM 33             /* Numerical argument out of domain */
#define ERANGE 34           /* Result too large */
#define EAGAIN 35           /* Resource temporarily unavailable */
#define EWOULDBLOCK EAGAIN  /* Operation would block */
#define EINPROGRESS 36      /* Operation now in progress */
#define EALREADY 37         /* Operation already in progress */
#define ENOTSOCK 38         /* Socket operation on non-socket */
#define EDESTADDRREQ 39     /* Destination address required */
#define EMSGSIZE 40         /* Message too long */
#define EPROTOTYPE 41       /* Protocol wrong type for socket */
#define ENOPROTOOPT 42      /* Protocol not available */
#define EPROTONOSUPPORT 43  /* Protocol not supported */
#define ESOCKTNOSUPPORT 44  /* Socket type not supported */
#define ENOTSUP 45          /* Operation not supported */
#define EPFNOSUPPORT 46     /* Protocol family not supported */
#define EAFNOSUPPORT 47     /* Address family not supported by protocol family */
#define EADDRINUSE 48       /* Address already in use */
#define EADDRNOTAVAIL 49    /* Can't assign requested address */
#define ENETDOWN 50         /* Network is down */
#define ENETUNREACH 51      /* Network is unreachable */
#define ENETRESET 52        /* Network dropped connection on reset */
#define ECONNABORTED 53     /* Software caused connection abort */
#define ECONNRESET 54       /* Connection reset by peer */
#define ENOBUFS 55          /* No buffer space available */
#define EISCONN 56          /* Socket is already connected */
#define ENOTCONN 57         /* Socket is not connected */
#define ESHUTDOWN 58        /* Can't send after socket shutdown */
#define ETOOMANYREFS 59     /* Too many references: can't splice */
#define ETIMEDOUT 60        /* Operation timed out */
#define ECONNREFUSED 61     /* Connection refused */
#define ELOOP 62            /* Too many levels of symbolic links */
#define ENAMETOOLONG 63     /* File name too long */
#define EHOSTDOWN 64        /* Host is down */
#define EHOSTUNREACH 65     /* No route to host */
#define ENOTEMPTY 66        /* Directory not empty */
#define EPROCLIM 67         /* Too many processes */
#define EUSERS 68           /* Too many users */
#define EDQUOT 69           /* Disc quota exceeded */
#define ESTALE 70           /* Stale NFS file handle */
#define EREMOTE 71          /* Too many levels of remote in path */
#define EBADRPC 72          /* RPC struct is bad */
#define ERPCMISMATCH 73     /* RPC version wrong */
#define EPROGUNAVAIL 74     /* RPC prog. not avail */
#define EPROGMISMATCH 75    /* Program version wrong */
#define EPROCUNAVAIL 76     /* Bad procedure for program */
#define ENOLCK 77           /* No locks available */
#define ENOSYS 78           /* Function not implemented */
#define EFTYPE 79           /* Inappropriate file type or format */
#define EAUTH 80            /* Authentication error */
#define ENEEDAUTH 81        /* Need authenticator */
#define EPWROFF 82          /* Device power is off */
#define EDEVERR 83          /* Device error, e.g. paper out */
#define EOVERFLOW 84        /* Value too large to be stored in data type */
#define EBADEXEC 85         /* Bad executable */
#define EBADARCH 86         /* Bad CPU type in executable */
#define ESHLIBVERS 87       /* Shared library version mismatch */
#define EBADMACHO 88        /* Malformed Macho file */
#define ECANCELED 89        /* Operation canceled */
#define EIDRM 90            /* Identifier removed */
#define ENOMSG 91           /* No message of desired type */
#define EILSEQ 92           /* Illegal byte sequence */
#define ENOATTR 93          /* Attribute not found */
#define EBADMSG 94          /* Bad message */
#define EMULTIHOP 95        /* Reserved */
#define ENODATA 96          /* No message available on STREAM */
#define ENOLINK 97          /* Reserved */
#define ENOSR 98            /* No STREAM resources */
#define ENOSTR 99           /* Not a STREAM */
#define EPROTO 100          /* Protocol error */
#define ETIME 101           /* STREAM ioctl timeout */
#define EOPNOTSUPP 102      /* Operation not supported on socket */
#define ENOPOLICY 103       /* No such policy registered */
#define ENOTRECOVERABLE 104 /* State not recoverable */
#define EOWNERDEAD 105      /* Previous owner died */
#define EQFULL 106          /* Interface output queue is full */
#define ELAST 106           /* Must be equal largest errno */

#define ERRORS                                                                                              \
    {                                                                                                       \
        "Undefined error: 0", "Operation not permitted", "No such file or directory", "No such process",    \
            "Interrupted system call", "Input/output error", "Device not configured",                       \
            "Argument list too long", "Exec format error", "Bad file descriptor", "No child processes",     \
            "Resource deadlock avoided", "Cannot allocate memory", "Permission denied", "Bad address",      \
            "Block device required", "Resource busy", "File exists", "Cross-device link",                   \
            "Operation not supported by device", "Not a directory", "Is a directory", "Invalid argument",   \
            "Too many open files in system", "Too many open files", "Inappropriate ioctl for device",       \
            "Text file busy", "File too large", "No space left on device", "Illegal seek",                  \
            "Read-only file system", "Too many links", "Broken pipe", "Numerical argument out of domain",   \
            "Result too large", "Resource temporarily unavailable", "Operation now in progress",            \
            "Operation already in progress", "Socket operation on non-socket",                              \
            "Destination address required", "Message too long", "Protocol wrong type for socket",           \
            "Protocol not available", "Protocol not supported", "Socket type not supported",                \
            "Operation not supported", "Protocol family not supported",                                     \
            "Address family not supported by protocol family", "Address already in use",                    \
            "Can't assign requested address", "Network is down", "Network is unreachable",                  \
            "Network dropped connection on reset", "Software caused connection abort",                      \
            "Connection reset by peer", "No buffer space available", "Socket is already connected",         \
            "Socket is not connected", "Can't send after socket shutdown",                                  \
            "Too many references: can't splice", "Operation timed out", "Connection refused",               \
            "Too many levels of symbolic links", "File name too long", "Host is down", "No route to host",  \
            "Directory not empty", "Too many processes", "Too many users", "Disc quota exceeded",           \
            "Stale NFS file handle", "Too many levels of remote in path", "RPC struct is bad",              \
            "RPC version wrong", "RPC prog. not avail", "Program version wrong",                            \
            "Bad procedure for program", "No locks available", "Function not implemented",                  \
            "Inappropriate file type or format", "Authentication error", "Need authenticator",              \
            "Device power is off", "Device error", "Value too large to be stored in data type",             \
            "Bad executable (or shared library)", "Bad CPU type in executable",                             \
            "Shared library version mismatch", "Malformed Mach-o file", "Operation canceled",               \
            "Identifier removed", "No message of desired type", "Illegal byte sequence",                    \
            "Attribute not found", "Bad message", "EMULTIHOP (Reserved)", "No message available on STREAM", \
            "ENOLINK (Reserved)", "No STREAM resources", "Not a STREAM", "Protocol error",                  \
            "STREAM ioctl timeout", "Operation not supported on socket", "Policy not found",                \
            "State not recoverable", "Previous owner died", "Interface output queue is full",               \
            "Unknown error:",                                                                               \
    }

#endif  //  __linux__

#endif  // SRC_S21_STRERROR_H_
