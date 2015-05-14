/*********************************************************************
 * NAN - Native Abstractions for Node.js
 *
 * Copyright (c) 2015 NAN contributors
 *
 * MIT License <https://github.com/iojs/nan/blob/master/LICENSE.md>
 ********************************************************************/

#include <nan.h>

NAN_METHOD(ReturnUndefined) {
  NanReturnUndefined();
}

void Init (v8::Handle<v8::Object> target) {
  NanSet(target
    , NanNew<v8::String>("r").ToLocalChecked()
    , NanNew<v8::FunctionTemplate>(ReturnUndefined)->GetFunction()
  );
}

NODE_MODULE(returnundefined, Init)

