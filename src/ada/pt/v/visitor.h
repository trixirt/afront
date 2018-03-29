#ifndef AFRONT_ADA_PT_V_VISITOR_H
#define AFRONT_ADA_PT_V_VISITOR_H

#include "../pt_classes.h"

class visitor {
public:
  visitor(){};
  virtual ~visitor(){};

#define VISITOR_ABSTRACT_CLASS
#include "visitor_methods.h"
#undef VISITOR_ABSTRACT_CLASS
  
  virtual void descend() {}
  virtual void ascend() {}
};

#endif
