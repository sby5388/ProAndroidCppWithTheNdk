/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 4.0.2
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

package com.shenby.swig;

public class AsyncProviderJNI {
  public final static native long new_AsyncUidProvider();
  public final static native void delete_AsyncUidProvider(long jarg1);
  public final static native void AsyncUidProvider_get(long jarg1, AsyncUidProvider jarg1_);
  public final static native void AsyncUidProvider_onUid(long jarg1, AsyncUidProvider jarg1_, long jarg2);
  public final static native void AsyncUidProvider_onUidSwigExplicitAsyncUidProvider(long jarg1, AsyncUidProvider jarg1_, long jarg2);
  public final static native void AsyncUidProvider_director_connect(AsyncUidProvider obj, long cptr, boolean mem_own, boolean weak_global);
  public final static native void AsyncUidProvider_change_ownership(AsyncUidProvider obj, long cptr, boolean take_or_release);

  public static void SwigDirector_AsyncUidProvider_onUid(AsyncUidProvider jself, long uid) {
    jself.onUid(uid);
  }

  private final static native void swig_module_init();
  static {
    swig_module_init();
  }
}
