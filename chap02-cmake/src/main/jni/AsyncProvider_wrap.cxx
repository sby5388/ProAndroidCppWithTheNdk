/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (https://www.swig.org).
 * Version 4.1.1
 *
 * Do not make changes to this file unless you know what you are doing - modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */


#define SWIG_VERSION 0x040101
#define SWIGJAVA
#define SWIG_DIRECTORS

/* -----------------------------------------------------------------------------
 *  This section contains generic SWIG labels for method/variable
 *  declarations/attributes, and other compiler dependent labels.
 * ----------------------------------------------------------------------------- */

/* template workaround for compilers that cannot correctly implement the C++ standard */
#ifndef SWIGTEMPLATEDISAMBIGUATOR
# if defined(__SUNPRO_CC) && (__SUNPRO_CC <= 0x560)
#  define SWIGTEMPLATEDISAMBIGUATOR template
# elif defined(__HP_aCC)
/* Needed even with `aCC -AA' when `aCC -V' reports HP ANSI C++ B3910B A.03.55 */
/* If we find a maximum version that requires this, the test would be __HP_aCC <= 35500 for A.03.55 */
#  define SWIGTEMPLATEDISAMBIGUATOR template
# else
#  define SWIGTEMPLATEDISAMBIGUATOR
# endif
#endif

/* inline attribute */
#ifndef SWIGINLINE
# if defined(__cplusplus) || (defined(__GNUC__) && !defined(__STRICT_ANSI__))
#   define SWIGINLINE inline
# else
#   define SWIGINLINE
# endif
#endif

/* attribute recognised by some compilers to avoid 'unused' warnings */
#ifndef SWIGUNUSED
# if defined(__GNUC__)
#   if !(defined(__cplusplus)) || (__GNUC__ > 3 || (__GNUC__ == 3 && __GNUC_MINOR__ >= 4))
#     define SWIGUNUSED __attribute__ ((__unused__))
#   else
#     define SWIGUNUSED
#   endif
# elif defined(__ICC)
#   define SWIGUNUSED __attribute__ ((__unused__))
# else
#   define SWIGUNUSED
# endif
#endif

#ifndef SWIG_MSC_UNSUPPRESS_4505
# if defined(_MSC_VER)
#   pragma warning(disable : 4505) /* unreferenced local function has been removed */
# endif
#endif

#ifndef SWIGUNUSEDPARM
# ifdef __cplusplus
#   define SWIGUNUSEDPARM(p)
# else
#   define SWIGUNUSEDPARM(p) p SWIGUNUSED
# endif
#endif

/* internal SWIG method */
#ifndef SWIGINTERN
# define SWIGINTERN static SWIGUNUSED
#endif

/* internal inline SWIG method */
#ifndef SWIGINTERNINLINE
# define SWIGINTERNINLINE SWIGINTERN SWIGINLINE
#endif

/* exporting methods */
#if defined(__GNUC__)
#  if (__GNUC__ >= 4) || (__GNUC__ == 3 && __GNUC_MINOR__ >= 4)
#    ifndef GCC_HASCLASSVISIBILITY
#      define GCC_HASCLASSVISIBILITY
#    endif
#  endif
#endif

#ifndef SWIGEXPORT
# if defined(_WIN32) || defined(__WIN32__) || defined(__CYGWIN__)
#   if defined(STATIC_LINKED)
#     define SWIGEXPORT
#   else
#     define SWIGEXPORT __declspec(dllexport)
#   endif
# else
#   if defined(__GNUC__) && defined(GCC_HASCLASSVISIBILITY)
#     define SWIGEXPORT __attribute__ ((visibility("default")))
#   else
#     define SWIGEXPORT
#   endif
# endif
#endif

/* calling conventions for Windows */
#ifndef SWIGSTDCALL
# if defined(_WIN32) || defined(__WIN32__) || defined(__CYGWIN__)
#   define SWIGSTDCALL __stdcall
# else
#   define SWIGSTDCALL
# endif
#endif

/* Deal with Microsoft's attempt at deprecating C standard runtime functions */
#if !defined(SWIG_NO_CRT_SECURE_NO_DEPRECATE) && defined(_MSC_VER) && !defined(_CRT_SECURE_NO_DEPRECATE)
# define _CRT_SECURE_NO_DEPRECATE
#endif

/* Deal with Microsoft's attempt at deprecating methods in the standard C++ library */
#if !defined(SWIG_NO_SCL_SECURE_NO_DEPRECATE) && defined(_MSC_VER) && !defined(_SCL_SECURE_NO_DEPRECATE)
# define _SCL_SECURE_NO_DEPRECATE
#endif

/* Deal with Apple's deprecated 'AssertMacros.h' from Carbon-framework */
#if defined(__APPLE__) && !defined(__ASSERT_MACROS_DEFINE_VERSIONS_WITHOUT_UNDERSCORES)
# define __ASSERT_MACROS_DEFINE_VERSIONS_WITHOUT_UNDERSCORES 0
#endif

/* Intel's compiler complains if a variable which was never initialised is
 * cast to void, which is a common idiom which we use to indicate that we
 * are aware a variable isn't used.  So we just silence that warning.
 * See: https://github.com/swig/swig/issues/192 for more discussion.
 */
#ifdef __INTEL_COMPILER
# pragma warning disable 592
#endif


#include <jni.h>
#include <stdlib.h>
#include <string.h>


/* Support for throwing Java exceptions */
typedef enum {
  SWIG_JavaOutOfMemoryError = 1,
  SWIG_JavaIOException,
  SWIG_JavaRuntimeException,
  SWIG_JavaIndexOutOfBoundsException,
  SWIG_JavaArithmeticException,
  SWIG_JavaIllegalArgumentException,
  SWIG_JavaNullPointerException,
  SWIG_JavaDirectorPureVirtual,
  SWIG_JavaUnknownError,
  SWIG_JavaIllegalStateException,
} SWIG_JavaExceptionCodes;

typedef struct {
  SWIG_JavaExceptionCodes code;
  const char *java_exception;
} SWIG_JavaExceptions_t;


static void SWIGUNUSED SWIG_JavaThrowException(JNIEnv *jenv, SWIG_JavaExceptionCodes code, const char *msg) {
  jclass excep;
  static const SWIG_JavaExceptions_t java_exceptions[] = {
    { SWIG_JavaOutOfMemoryError, "java/lang/OutOfMemoryError" },
    { SWIG_JavaIOException, "java/io/IOException" },
    { SWIG_JavaRuntimeException, "java/lang/RuntimeException" },
    { SWIG_JavaIndexOutOfBoundsException, "java/lang/IndexOutOfBoundsException" },
    { SWIG_JavaArithmeticException, "java/lang/ArithmeticException" },
    { SWIG_JavaIllegalArgumentException, "java/lang/IllegalArgumentException" },
    { SWIG_JavaNullPointerException, "java/lang/NullPointerException" },
    { SWIG_JavaDirectorPureVirtual, "java/lang/RuntimeException" },
    { SWIG_JavaUnknownError,  "java/lang/UnknownError" },
    { SWIG_JavaIllegalStateException, "java/lang/IllegalStateException" },
    { (SWIG_JavaExceptionCodes)0,  "java/lang/UnknownError" }
  };
  const SWIG_JavaExceptions_t *except_ptr = java_exceptions;

  while (except_ptr->code != code && except_ptr->code)
    except_ptr++;

  jenv->ExceptionClear();
  excep = jenv->FindClass(except_ptr->java_exception);
  if (excep)
    jenv->ThrowNew(excep, msg);
}


/* Contract support */

#define SWIG_contract_assert(nullreturn, expr, msg) do { if (!(expr)) {SWIG_JavaThrowException(jenv, SWIG_JavaIllegalArgumentException, msg); return nullreturn; } } while (0)

/* -----------------------------------------------------------------------------
 * director_common.swg
 *
 * This file contains support for director classes which is common between
 * languages.
 * ----------------------------------------------------------------------------- */

/*
  Use -DSWIG_DIRECTOR_STATIC if you prefer to avoid the use of the
  'Swig' namespace. This could be useful for multi-modules projects.
*/
#ifdef SWIG_DIRECTOR_STATIC
/* Force anonymous (static) namespace */
#define Swig
#endif
/* -----------------------------------------------------------------------------
 * director.swg
 *
 * This file contains support for director classes so that Java proxy
 * methods can be called from C++.
 * ----------------------------------------------------------------------------- */

#if defined(DEBUG_DIRECTOR_OWNED) || defined(DEBUG_DIRECTOR_EXCEPTION) || defined(DEBUG_DIRECTOR_THREAD_NAME)
#include <iostream>
#endif

#include <exception>

#if defined(SWIG_JAVA_USE_THREAD_NAME)

#if !defined(SWIG_JAVA_GET_THREAD_NAME)
namespace Swig {
  SWIGINTERN int GetThreadName(char *name, size_t len);
}

#if defined(__linux__)

#include <sys/prctl.h>
SWIGINTERN int Swig::GetThreadName(char *name, size_t len) {
  (void)len;
#if defined(PR_GET_NAME)
  return prctl(PR_GET_NAME, (unsigned long)name, 0, 0, 0);
#else
  (void)name;
  return 1;
#endif
}

#elif defined(__unix__) || defined(__APPLE__)

#include <pthread.h>
SWIGINTERN int Swig::GetThreadName(char *name, size_t len) {
  return pthread_getname_np(pthread_self(), name, len);
}

#else

SWIGINTERN int Swig::GetThreadName(char *name, size_t len) {
  (void)len;
  (void)name;
  return 1;
}
#endif

#endif

#endif

#if defined(SWIG_JAVA_DETACH_ON_THREAD_END)
#include <pthread.h>
#endif

namespace Swig {

  /* Java object wrapper */
  class JObjectWrapper {
  public:
    JObjectWrapper() : jthis_(NULL), weak_global_(true) {
    }

    ~JObjectWrapper() {
      jthis_ = NULL;
      weak_global_ = true;
    }

    bool set(JNIEnv *jenv, jobject jobj, bool mem_own, bool weak_global) {
      if (!jthis_) {
        weak_global_ = weak_global || !mem_own; // hold as weak global if explicitly requested or not owned
        if (jobj)
          jthis_ = weak_global_ ? jenv->NewWeakGlobalRef(jobj) : jenv->NewGlobalRef(jobj);
#if defined(DEBUG_DIRECTOR_OWNED)
        std::cout << "JObjectWrapper::set(" << jobj << ", " << (weak_global ? "weak_global" : "global_ref") << ") -> " << jthis_ << std::endl;
#endif
        return true;
      } else {
#if defined(DEBUG_DIRECTOR_OWNED)
        std::cout << "JObjectWrapper::set(" << jobj << ", " << (weak_global ? "weak_global" : "global_ref") << ") -> already set" << std::endl;
#endif
        return false;
      }
    }

    jobject get(JNIEnv *jenv) const {
#if defined(DEBUG_DIRECTOR_OWNED)
      std::cout << "JObjectWrapper::get(";
      if (jthis_)
        std::cout << jthis_;
      else
        std::cout << "null";
      std::cout << ") -> return new local ref" << std::endl;
#endif
      return (jthis_ ? jenv->NewLocalRef(jthis_) : jthis_);
    }

    void release(JNIEnv *jenv) {
#if defined(DEBUG_DIRECTOR_OWNED)
      std::cout << "JObjectWrapper::release(" << jthis_ << "): " << (weak_global_ ? "weak global ref" : "global ref") << std::endl;
#endif
      if (jthis_) {
        if (weak_global_) {
          if (jenv->IsSameObject(jthis_, NULL) == JNI_FALSE)
            jenv->DeleteWeakGlobalRef((jweak)jthis_);
        } else
          jenv->DeleteGlobalRef(jthis_);
      }

      jthis_ = NULL;
      weak_global_ = true;
    }

    /* Only call peek if you know what you are doing wrt to weak/global references */
    jobject peek() {
      return jthis_;
    }

    /* Java proxy releases ownership of C++ object, C++ object is now
       responsible for destruction (creates NewGlobalRef to pin Java proxy) */
    void java_change_ownership(JNIEnv *jenv, jobject jself, bool take_or_release) {
      if (take_or_release) {  /* Java takes ownership of C++ object's lifetime. */
        if (!weak_global_) {
          jenv->DeleteGlobalRef(jthis_);
          jthis_ = jenv->NewWeakGlobalRef(jself);
          weak_global_ = true;
        }
      } else {
	/* Java releases ownership of C++ object's lifetime */
        if (weak_global_) {
          jenv->DeleteWeakGlobalRef((jweak)jthis_);
          jthis_ = jenv->NewGlobalRef(jself);
          weak_global_ = false;
        }
      }
    }

#if defined(SWIG_JAVA_DETACH_ON_THREAD_END)
    static void detach(void *jvm) {
      static_cast<JavaVM *>(jvm)->DetachCurrentThread();
    }

    static void make_detach_key() {
      pthread_key_create(&detach_key_, detach);
    }

    /* thread-local key to register a destructor */
    static pthread_key_t detach_key_;
#endif

  private:
    /* pointer to Java object */
    jobject jthis_;
    /* Local or global reference flag */
    bool weak_global_;
  };

#if defined(SWIG_JAVA_DETACH_ON_THREAD_END)
  pthread_key_t JObjectWrapper::detach_key_;
#endif

  /* Local JNI reference deleter */
  class LocalRefGuard {
    JNIEnv *jenv_;
    jobject jobj_;

    // non-copyable
    LocalRefGuard(const LocalRefGuard &);
    LocalRefGuard &operator=(const LocalRefGuard &);
  public:
    LocalRefGuard(JNIEnv *jenv, jobject jobj): jenv_(jenv), jobj_(jobj) {}
    ~LocalRefGuard() {
      if (jobj_)
        jenv_->DeleteLocalRef(jobj_);
    }
  };

  /* director base class */
  class Director {
    /* pointer to Java virtual machine */
    JavaVM *swig_jvm_;

  protected:
#if defined (_MSC_VER) && (_MSC_VER<1300)
    class JNIEnvWrapper;
    friend class JNIEnvWrapper;
#endif
    /* Utility class for managing the JNI environment */
    class JNIEnvWrapper {
      const Director *director_;
      JNIEnv *jenv_;
      int env_status;
    public:
      JNIEnvWrapper(const Director *director) : director_(director), jenv_(0), env_status(0) {
#if defined(__ANDROID__)
        JNIEnv **jenv = &jenv_;
#else
        void **jenv = (void **)&jenv_;
#endif
        env_status = director_->swig_jvm_->GetEnv((void **)&jenv_, JNI_VERSION_1_2);
        JavaVMAttachArgs args;
        args.version = JNI_VERSION_1_2;
        args.group = NULL;
        args.name = NULL;
#if defined(SWIG_JAVA_USE_THREAD_NAME)
        char thread_name[64];  // MAX_TASK_COMM_LEN=16 is hard-coded in the Linux kernel and MacOS has MAXTHREADNAMESIZE=64.
        if (Swig::GetThreadName(thread_name, sizeof(thread_name)) == 0) {
          args.name = thread_name;
#if defined(DEBUG_DIRECTOR_THREAD_NAME)
          std::cout << "JNIEnvWrapper: thread name: " << thread_name << std::endl;
        } else {
          std::cout << "JNIEnvWrapper: Couldn't set Java thread name" << std::endl;
#endif
        }
#endif
#if defined(SWIG_JAVA_ATTACH_CURRENT_THREAD_AS_DAEMON)
        // Attach a daemon thread to the JVM. Useful when the JVM should not wait for
        // the thread to exit upon shutdown. Only for jdk-1.4 and later.
        director_->swig_jvm_->AttachCurrentThreadAsDaemon(jenv, &args);
#else
        director_->swig_jvm_->AttachCurrentThread(jenv, &args);
#endif

#if defined(SWIG_JAVA_DETACH_ON_THREAD_END)
        // At least on Android 6, detaching after every call causes a memory leak.
        // Instead, register a thread desructor and detach only when the thread ends.
        // See https://developer.android.com/training/articles/perf-jni#threads
        static pthread_once_t once = PTHREAD_ONCE_INIT;

        pthread_once(&once, JObjectWrapper::make_detach_key);
        pthread_setspecific(JObjectWrapper::detach_key_, director->swig_jvm_);
#endif
      }
      ~JNIEnvWrapper() {
#if !defined(SWIG_JAVA_DETACH_ON_THREAD_END) && !defined(SWIG_JAVA_NO_DETACH_CURRENT_THREAD)
        // Some JVMs, eg jdk-1.4.2 and lower on Solaris have a bug and crash with the DetachCurrentThread call.
        // However, without this call, the JVM hangs on exit when the thread was not created by the JVM and creates a memory leak.
        if (env_status == JNI_EDETACHED)
          director_->swig_jvm_->DetachCurrentThread();
#endif
      }
      JNIEnv *getJNIEnv() const {
        return jenv_;
      }
    };

    struct SwigDirectorMethod {
      const char *name;
      const char *desc;
      jmethodID methid;
      SwigDirectorMethod(JNIEnv *jenv, jclass baseclass, const char *name, const char *desc) : name(name), desc(desc) {
        methid = jenv->GetMethodID(baseclass, name, desc);
      }
    };

    /* Java object wrapper */
    JObjectWrapper swig_self_;

    /* Disconnect director from Java object */
    void swig_disconnect_director_self(const char *disconn_method) {
      JNIEnvWrapper jnienv(this) ;
      JNIEnv *jenv = jnienv.getJNIEnv() ;
      jobject jobj = swig_self_.get(jenv);
      LocalRefGuard ref_deleter(jenv, jobj);
#if defined(DEBUG_DIRECTOR_OWNED)
      std::cout << "Swig::Director::disconnect_director_self(" << jobj << ")" << std::endl;
#endif
      if (jobj && jenv->IsSameObject(jobj, NULL) == JNI_FALSE) {
        jmethodID disconn_meth = jenv->GetMethodID(jenv->GetObjectClass(jobj), disconn_method, "()V");
        if (disconn_meth) {
#if defined(DEBUG_DIRECTOR_OWNED)
          std::cout << "Swig::Director::disconnect_director_self upcall to " << disconn_method << std::endl;
#endif
          jenv->CallVoidMethod(jobj, disconn_meth);
        }
      }
    }

    jclass swig_new_global_ref(JNIEnv *jenv, const char *classname) {
      jclass clz = jenv->FindClass(classname);
      return clz ? (jclass)jenv->NewGlobalRef(clz) : 0;
    }

  public:
    Director(JNIEnv *jenv) : swig_jvm_((JavaVM *) NULL), swig_self_() {
      /* Acquire the Java VM pointer */
      jenv->GetJavaVM(&swig_jvm_);
    }

    virtual ~Director() {
      JNIEnvWrapper jnienv(this) ;
      JNIEnv *jenv = jnienv.getJNIEnv() ;
      swig_self_.release(jenv);
    }

    bool swig_set_self(JNIEnv *jenv, jobject jself, bool mem_own, bool weak_global) {
      return swig_self_.set(jenv, jself, mem_own, weak_global);
    }

    jobject swig_get_self(JNIEnv *jenv) const {
      return swig_self_.get(jenv);
    }

    // Change C++ object's ownership, relative to Java
    void swig_java_change_ownership(JNIEnv *jenv, jobject jself, bool take_or_release) {
      swig_self_.java_change_ownership(jenv, jself, take_or_release);
    }
  };

  // Zero initialized bool array
  template<size_t N> class BoolArray {
    bool array_[N];
  public:
    BoolArray() {
      memset(array_, 0, sizeof(array_));
    }
    bool& operator[](size_t n) {
      return array_[n];
    }
    bool operator[](size_t n) const {
      return array_[n];
    }
  };

  // Utility classes and functions for exception handling.

  // Simple holder for a Java string during exception handling, providing access to a c-style string
  class JavaString {
  public:
    JavaString(JNIEnv *jenv, jstring jstr) : jenv_(jenv), jstr_(jstr), cstr_(0) {
      if (jenv_ && jstr_)
	cstr_ = (const char *) jenv_->GetStringUTFChars(jstr_, NULL);
    }

    ~JavaString() {
      if (jenv_ && jstr_ && cstr_)
	jenv_->ReleaseStringUTFChars(jstr_, cstr_);
    }

    const char *c_str(const char *null_string = "null JavaString") const {
      return cstr_ ? cstr_ : null_string;
    }

  private:
    // non-copyable
    JavaString(const JavaString &);
    JavaString &operator=(const JavaString &);

    JNIEnv *jenv_;
    jstring jstr_;
    const char *cstr_;
  };

  // Helper class to extract the exception message from a Java throwable
  class JavaExceptionMessage {
  public:
    JavaExceptionMessage(JNIEnv *jenv, jthrowable throwable) : message_(jenv, exceptionMessageFromThrowable(jenv, throwable)) {
    }

    // Return a C string of the exception message in the jthrowable passed in the constructor
    // If no message is available, null_string is return instead
    const char *message(const char *null_string = "Could not get exception message in JavaExceptionMessage") const {
      return message_.c_str(null_string);
    }

  private:
    // non-copyable
    JavaExceptionMessage(const JavaExceptionMessage &);
    JavaExceptionMessage &operator=(const JavaExceptionMessage &);

    // Get exception message by calling Java method Throwable.getMessage()
    static jstring exceptionMessageFromThrowable(JNIEnv *jenv, jthrowable throwable) {
      jstring jmsg = NULL;
      if (jenv && throwable) {
	jenv->ExceptionClear(); // Cannot invoke methods with any pending exceptions
	jclass throwclz = jenv->GetObjectClass(throwable);
	if (throwclz) {
	  // All Throwable classes have a getMessage() method, so call it to extract the exception message
	  jmethodID getMessageMethodID = jenv->GetMethodID(throwclz, "getMessage", "()Ljava/lang/String;");
	  if (getMessageMethodID)
	    jmsg = (jstring)jenv->CallObjectMethod(throwable, getMessageMethodID);
	}
	if (jmsg == NULL && jenv->ExceptionCheck())
	  jenv->ExceptionClear();
      }
      return jmsg;
    }

    JavaString message_;
  };

  // C++ Exception class for handling Java exceptions thrown during a director method Java upcall
  class DirectorException : public std::exception {
  public:

    // Construct exception from a Java throwable
    DirectorException(JNIEnv *jenv, jthrowable throwable) : jenv_(jenv), throwable_(throwable), classname_(0), msg_(0) {

      // Call Java method Object.getClass().getName() to obtain the throwable's class name (delimited by '/')
      if (jenv && throwable) {
	jenv->ExceptionClear(); // Cannot invoke methods with any pending exceptions
	jclass throwclz = jenv->GetObjectClass(throwable);
	if (throwclz) {
	  jclass clzclz = jenv->GetObjectClass(throwclz);
	  if (clzclz) {
	    jmethodID getNameMethodID = jenv->GetMethodID(clzclz, "getName", "()Ljava/lang/String;");
	    if (getNameMethodID) {
	      jstring jstr_classname = (jstring)(jenv->CallObjectMethod(throwclz, getNameMethodID));
              // Copy strings, since there is no guarantee that jenv will be active when handled
              if (jstr_classname) {
                JavaString jsclassname(jenv, jstr_classname);
                const char *classname = jsclassname.c_str(0);
                if (classname)
                  classname_ = copypath(classname);
              }
	    }
	  }
	}
      }

      JavaExceptionMessage exceptionmsg(jenv, throwable);
      msg_ = copystr(exceptionmsg.message(0));
    }

    // More general constructor for handling as a java.lang.RuntimeException
    DirectorException(const char *msg) : jenv_(0), throwable_(0), classname_(0), msg_(msg ? copystr(msg) : 0) {
    }

    ~DirectorException() throw() {
      delete[] classname_;
      delete[] msg_;
    }

    const char *what() const throw() {
      return msg_ ? msg_ : "Unspecified DirectorException message";
    }

    // Reconstruct and raise/throw the Java Exception that caused the DirectorException
    // Note that any error in the JNI exception handling results in a Java RuntimeException
    void throwException(JNIEnv *jenv) const {
      if (jenv) {
        if (jenv == jenv_ && throwable_) {
          // Throw original exception if not already pending
          jthrowable throwable = jenv->ExceptionOccurred();
          if (throwable && jenv->IsSameObject(throwable, throwable_) == JNI_FALSE) {
            jenv->ExceptionClear();
            throwable = 0;
          }
          if (!throwable)
            jenv->Throw(throwable_);
        } else {
          // Try and reconstruct original exception, but original stacktrace is not reconstructed
          jenv->ExceptionClear();

          jmethodID ctorMethodID = 0;
          jclass throwableclass = 0;
          if (classname_) {
            throwableclass = jenv->FindClass(classname_);
            if (throwableclass)
              ctorMethodID = jenv->GetMethodID(throwableclass, "<init>", "(Ljava/lang/String;)V");
          }

          if (ctorMethodID) {
            jenv->ThrowNew(throwableclass, what());
          } else {
            SWIG_JavaThrowException(jenv, SWIG_JavaRuntimeException, what());
          }
        }
      }
    }

    // Deprecated - use throwException
    void raiseJavaException(JNIEnv *jenv) const {
      throwException(jenv);
    }

    // Create and throw the DirectorException
    static void raise(JNIEnv *jenv, jthrowable throwable) {
      throw DirectorException(jenv, throwable);
    }

  private:
    static char *copypath(const char *srcmsg) {
      char *target = copystr(srcmsg);
      for (char *c=target; *c; ++c) {
        if ('.' == *c)
          *c = '/';
      }
      return target;
    }

    static char *copystr(const char *srcmsg) {
      char *target = 0;
      if (srcmsg) {
	size_t msglen = strlen(srcmsg) + 1;
	target = new char[msglen];
	strncpy(target, srcmsg, msglen);
      }
      return target;
    }

    JNIEnv *jenv_;
    jthrowable throwable_;
    const char *classname_;
    const char *msg_;
  };

  // Helper method to determine if a Java throwable matches a particular Java class type
  // Note side effect of clearing any pending exceptions
  SWIGINTERN bool ExceptionMatches(JNIEnv *jenv, jthrowable throwable, const char *classname) {
    bool matches = false;

    if (throwable && jenv && classname) {
      // Exceptions need to be cleared for correct behavior.
      // The caller of ExceptionMatches should restore pending exceptions if desired -
      // the caller already has the throwable.
      jenv->ExceptionClear();

      jclass clz = jenv->FindClass(classname);
      if (clz) {
	jclass classclz = jenv->GetObjectClass(clz);
	jmethodID isInstanceMethodID = jenv->GetMethodID(classclz, "isInstance", "(Ljava/lang/Object;)Z");
	if (isInstanceMethodID) {
	  matches = jenv->CallBooleanMethod(clz, isInstanceMethodID, throwable) != 0;
	}
      }

#if defined(DEBUG_DIRECTOR_EXCEPTION)
      if (jenv->ExceptionCheck()) {
        // Typically occurs when an invalid classname argument is passed resulting in a ClassNotFoundException
        JavaExceptionMessage exc(jenv, jenv->ExceptionOccurred());
        std::cout << "Error: ExceptionMatches: class '" << classname << "' : " << exc.message() << std::endl;
      }
#endif
    }
    return matches;
  }
}

namespace Swig {
  namespace {
    jclass jclass_AsyncProviderJNI = NULL;
    jmethodID director_method_ids[1];
  }
}

#ifdef __cplusplus
#include <utility>
/* SwigValueWrapper is described in swig.swg */
template<typename T> class SwigValueWrapper {
  struct SwigSmartPointer {
    T *ptr;
    SwigSmartPointer(T *p) : ptr(p) { }
    ~SwigSmartPointer() { delete ptr; }
    SwigSmartPointer& operator=(SwigSmartPointer& rhs) { T* oldptr = ptr; ptr = 0; delete oldptr; ptr = rhs.ptr; rhs.ptr = 0; return *this; }
    void reset(T *p) { T* oldptr = ptr; ptr = 0; delete oldptr; ptr = p; }
  } pointer;
  SwigValueWrapper& operator=(const SwigValueWrapper<T>& rhs);
  SwigValueWrapper(const SwigValueWrapper<T>& rhs);
public:
  SwigValueWrapper() : pointer(0) { }
  SwigValueWrapper& operator=(const T& t) { SwigSmartPointer tmp(new T(t)); pointer = tmp; return *this; }
#if __cplusplus >=201103L
  SwigValueWrapper& operator=(T&& t) { SwigSmartPointer tmp(new T(std::move(t))); pointer = tmp; return *this; }
  operator T&&() const { return std::move(*pointer.ptr); }
#else
  operator T&() const { return *pointer.ptr; }
#endif
  T *operator&() const { return pointer.ptr; }
  static void reset(SwigValueWrapper& t, T *p) { t.pointer.reset(p); }
};

/*
 * SwigValueInit() is a generic initialisation solution as the following approach:
 * 
 *       T c_result = T();
 * 
 * doesn't compile for all types for example:
 * 
 *       unsigned int c_result = unsigned int();
 */
template <typename T> T SwigValueInit() {
  return T();
}

#if __cplusplus >=201103L
# define SWIG_STD_MOVE(OBJ) std::move(OBJ)
#else
# define SWIG_STD_MOVE(OBJ) OBJ
#endif

#endif


/** 包含POSIX 操作系统API */
#include <unistd.h>
#include "AsyncUidProvider.hpp"




/* ---------------------------------------------------
 * C++ director class methods
 * --------------------------------------------------- */

#include "AsyncProvider_wrap.h"

SwigDirector_AsyncUidProvider::SwigDirector_AsyncUidProvider(JNIEnv *jenv) : AsyncUidProvider(), Swig::Director(jenv) {
}

SwigDirector_AsyncUidProvider::~SwigDirector_AsyncUidProvider() {
  swig_disconnect_director_self("swigDirectorDisconnect");
}


void SwigDirector_AsyncUidProvider::onUid(uid_t uid) {
  JNIEnvWrapper swigjnienv(this) ;
  JNIEnv * jenv = swigjnienv.getJNIEnv() ;
  jobject swigjobj = (jobject) NULL ;
  jlong juid  ;
  
  if (!swig_override[0]) {
    AsyncUidProvider::onUid(uid);
    return;
  }
  swigjobj = swig_get_self(jenv);
  if (swigjobj && jenv->IsSameObject(swigjobj, NULL) == JNI_FALSE) {
    juid = (jlong) uid;
    jenv->CallStaticVoidMethod(Swig::jclass_AsyncProviderJNI, Swig::director_method_ids[0], swigjobj, juid);
    jthrowable swigerror = jenv->ExceptionOccurred();
    if (swigerror) {
      Swig::DirectorException::raise(jenv, swigerror);
    }
    
  } else {
    SWIG_JavaThrowException(jenv, SWIG_JavaNullPointerException, "null upcall object in AsyncUidProvider::onUid ");
  }
  if (swigjobj) jenv->DeleteLocalRef(swigjobj);
}

void SwigDirector_AsyncUidProvider::swig_connect_director(JNIEnv *jenv, jobject jself, jclass jcls, bool swig_mem_own, bool weak_global) {
  static jclass baseclass = swig_new_global_ref(jenv, "com/shenby/swig/AsyncUidProvider");
  if (!baseclass) return;
  static SwigDirectorMethod methods[] = {
    SwigDirectorMethod(jenv, baseclass, "onUid", "(J)V")
  };
  
  if (swig_set_self(jenv, jself, swig_mem_own, weak_global)) {
    bool derived = (jenv->IsSameObject(baseclass, jcls) ? false : true);
    for (int i = 0; i < 1; ++i) {
      swig_override[i] = false;
      if (derived) {
        jmethodID methid = jenv->GetMethodID(jcls, methods[i].name, methods[i].desc);
        swig_override[i] = methods[i].methid && (methid != methods[i].methid);
        jenv->ExceptionClear();
      }
    }
  }
}



#ifdef __cplusplus
extern "C" {
#endif

SWIGEXPORT jlong JNICALL Java_com_shenby_swig_AsyncProviderJNI_new_1AsyncUidProvider(JNIEnv *jenv, jclass jcls) {
  jlong jresult = 0 ;
  AsyncUidProvider *result = 0 ;
  
  (void)jenv;
  (void)jcls;
  result = (AsyncUidProvider *)new SwigDirector_AsyncUidProvider(jenv);
  *(AsyncUidProvider **)&jresult = result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_com_shenby_swig_AsyncProviderJNI_delete_1AsyncUidProvider(JNIEnv *jenv, jclass jcls, jlong jarg1) {
  AsyncUidProvider *arg1 = (AsyncUidProvider *) 0 ;
  
  (void)jenv;
  (void)jcls;
  arg1 = *(AsyncUidProvider **)&jarg1; 
  delete arg1;
}


SWIGEXPORT void JNICALL Java_com_shenby_swig_AsyncProviderJNI_AsyncUidProvider_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  AsyncUidProvider *arg1 = (AsyncUidProvider *) 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(AsyncUidProvider **)&jarg1; 
  (arg1)->get();
}


SWIGEXPORT void JNICALL Java_com_shenby_swig_AsyncProviderJNI_AsyncUidProvider_1onUid(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlong jarg2) {
  AsyncUidProvider *arg1 = (AsyncUidProvider *) 0 ;
  uid_t arg2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(AsyncUidProvider **)&jarg1; 
  arg2 = (uid_t)jarg2; 
  (arg1)->onUid(arg2);
}


SWIGEXPORT void JNICALL Java_com_shenby_swig_AsyncProviderJNI_AsyncUidProvider_1onUidSwigExplicitAsyncUidProvider(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlong jarg2) {
  AsyncUidProvider *arg1 = (AsyncUidProvider *) 0 ;
  uid_t arg2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(AsyncUidProvider **)&jarg1; 
  arg2 = (uid_t)jarg2; 
  (arg1)->AsyncUidProvider::onUid(arg2);
}


SWIGEXPORT void JNICALL Java_com_shenby_swig_AsyncProviderJNI_AsyncUidProvider_1director_1connect(JNIEnv *jenv, jclass jcls, jobject jself, jlong objarg, jboolean jswig_mem_own, jboolean jweak_global) {
  AsyncUidProvider *obj = *((AsyncUidProvider **)&objarg);
  (void)jcls;
  SwigDirector_AsyncUidProvider *director = static_cast<SwigDirector_AsyncUidProvider *>(obj);
  director->swig_connect_director(jenv, jself, jenv->GetObjectClass(jself), (jswig_mem_own == JNI_TRUE), (jweak_global == JNI_TRUE));
}


SWIGEXPORT void JNICALL Java_com_shenby_swig_AsyncProviderJNI_AsyncUidProvider_1change_1ownership(JNIEnv *jenv, jclass jcls, jobject jself, jlong objarg, jboolean jtake_or_release) {
  AsyncUidProvider *obj = *((AsyncUidProvider **)&objarg);
  SwigDirector_AsyncUidProvider *director = dynamic_cast<SwigDirector_AsyncUidProvider *>(obj);
  (void)jcls;
  if (director) {
    director->swig_java_change_ownership(jenv, jself, jtake_or_release ? true : false);
  }
}


SWIGEXPORT void JNICALL Java_com_shenby_swig_AsyncProviderJNI_swig_1module_1init(JNIEnv *jenv, jclass jcls) {
  int i;
  
  static struct {
    const char *method;
    const char *signature;
  } methods[1] = {
    {
      "SwigDirector_AsyncUidProvider_onUid", "(Lcom/shenby/swig/AsyncUidProvider;J)V" 
    }
  };
  Swig::jclass_AsyncProviderJNI = (jclass) jenv->NewGlobalRef(jcls);
  if (!Swig::jclass_AsyncProviderJNI) return;
  for (i = 0; i < (int) (sizeof(methods)/sizeof(methods[0])); ++i) {
    Swig::director_method_ids[i] = jenv->GetStaticMethodID(jcls, methods[i].method, methods[i].signature);
    if (!Swig::director_method_ids[i]) return;
  }
}


#ifdef __cplusplus
}
#endif

