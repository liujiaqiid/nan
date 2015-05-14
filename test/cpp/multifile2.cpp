/*********************************************************************
 * NAN - Native Abstractions for Node.js
 *
 * Copyright (c) 2015 NAN contributors
 *
 * MIT License <https://github.com/iojs/nan/blob/master/LICENSE.md>
 ********************************************************************/

#include <nan.h>

NAN_METHOD(ReturnString) {
  v8::Local<v8::String> s =
      NanNew<v8::String>(*NanUtf8String(args[0])).ToLocalChecked();
  NanReturnValue(s);
}
