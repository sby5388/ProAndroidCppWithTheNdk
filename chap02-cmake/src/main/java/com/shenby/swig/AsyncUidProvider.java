/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 4.0.2
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

package com.shenby.swig;

public class AsyncUidProvider {
  private transient long swigCPtr;
  protected transient boolean swigCMemOwn;

  protected AsyncUidProvider(long cPtr, boolean cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = cPtr;
  }

  protected static long getCPtr(AsyncUidProvider obj) {
    return (obj == null) ? 0 : obj.swigCPtr;
  }

  @SuppressWarnings("deprecation")
  protected void finalize() {
    delete();
  }

  public synchronized void delete() {
    if (swigCPtr != 0) {
      if (swigCMemOwn) {
        swigCMemOwn = false;
        AsyncProviderJNI.delete_AsyncUidProvider(swigCPtr);
      }
      swigCPtr = 0;
    }
  }

  protected void swigDirectorDisconnect() {
    swigCMemOwn = false;
    delete();
  }

  public void swigReleaseOwnership() {
    swigCMemOwn = false;
    AsyncProviderJNI.AsyncUidProvider_change_ownership(this, swigCPtr, false);
  }

  public void swigTakeOwnership() {
    swigCMemOwn = true;
    AsyncProviderJNI.AsyncUidProvider_change_ownership(this, swigCPtr, true);
  }

  public AsyncUidProvider() {
    this(AsyncProviderJNI.new_AsyncUidProvider(), true);
    AsyncProviderJNI.AsyncUidProvider_director_connect(this, swigCPtr, true, true);
  }

  public void get() {
    AsyncProviderJNI.AsyncUidProvider_get(swigCPtr, this);
  }

  public void onUid(long uid) {
    if (getClass() == AsyncUidProvider.class) AsyncProviderJNI.AsyncUidProvider_onUid(swigCPtr, this, uid); else AsyncProviderJNI.AsyncUidProvider_onUidSwigExplicitAsyncUidProvider(swigCPtr, this, uid);
  }

}