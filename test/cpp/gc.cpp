/*********************************************************************
 * NAN - Native Abstractions for Node.js
 *
 * Copyright (c) 2015 NAN contributors
 *
 * MIT License <https://github.com/iojs/nan/blob/master/LICENSE.md>
 ********************************************************************/

#include <nan.h>

static bool prologue_called = false;
static bool epilogue_called = false;

NAN_GC_CALLBACK(gcPrologueCallback) {
  prologue_called = true;
}

NAN_GC_CALLBACK(gcEpilogueCallback) {
  epilogue_called = true;
}

NAN_METHOD(Hook) {
  NanAddGCPrologueCallback(gcPrologueCallback);
  NanAddGCEpilogueCallback(gcEpilogueCallback);
  NanReturnUndefined();
}

NAN_METHOD(Check) {
  NanReturnValue(NanNew(prologue_called && epilogue_called));
}

void Init (v8::Handle<v8::Object> target) {
  NanSet(target
    , NanNew<v8::String>("hook").ToLocalChecked()
    , NanNew<v8::FunctionTemplate>(Hook)->GetFunction()
  );
  NanSet(target
    , NanNew<v8::String>("check").ToLocalChecked()
    , NanNew<v8::FunctionTemplate>(Check)->GetFunction()
  );
}

NODE_MODULE(gc, Init)
