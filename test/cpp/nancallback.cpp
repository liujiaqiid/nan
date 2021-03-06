/*********************************************************************
 * NAN - Native Abstractions for Node.js
 *
 * Copyright (c) 2015 NAN contributors
 *
 * MIT License <https://github.com/iojs/nan/blob/master/LICENSE.md>
 ********************************************************************/

#include <nan.h>


NAN_METHOD(GlobalContext) {
  NanScope();

  NanCallback(args[0].As<v8::Function>()).Call(0, NULL);
  NanReturnUndefined();
}

NAN_METHOD(SpecificContext) {
  NanScope();

  NanCallback cb(args[0].As<v8::Function>());
  cb.Call(NanGetCurrentContext()->Global(), 0, NULL);
  NanReturnUndefined();
}

NAN_METHOD(CompareCallbacks) {
  NanScope();

  NanCallback cb1(args[0].As<v8::Function>());
  NanCallback cb2(args[1].As<v8::Function>());
  NanCallback cb3(args[2].As<v8::Function>());

  NanReturnValue(NanNew<v8::Boolean>(cb1 == cb2 && cb1 != cb3));
}

void Init (v8::Handle<v8::Object> target) {
  target->Set(
      NanNew<v8::String>("globalContext")
    , NanNew<v8::FunctionTemplate>(GlobalContext)->GetFunction()
  );
  target->Set(
      NanNew<v8::String>("specificContext")
    , NanNew<v8::FunctionTemplate>(SpecificContext)->GetFunction()
  );
  target->Set(
      NanNew<v8::String>("compareCallbacks")
    , NanNew<v8::FunctionTemplate>(CompareCallbacks)->GetFunction()
  );
}

NODE_MODULE(nancallback, Init)
