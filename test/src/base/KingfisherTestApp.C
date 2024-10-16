//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "KingfisherTestApp.h"
#include "KingfisherApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"

InputParameters
KingfisherTestApp::validParams()
{
  InputParameters params = KingfisherApp::validParams();
  params.set<bool>("use_legacy_material_output") = false;
  params.set<bool>("use_legacy_initial_residual_evaluation_behavior") = false;
  return params;
}

KingfisherTestApp::KingfisherTestApp(InputParameters parameters) : MooseApp(parameters)
{
  KingfisherTestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

KingfisherTestApp::~KingfisherTestApp() {}

void
KingfisherTestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  KingfisherApp::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"KingfisherTestApp"});
    Registry::registerActionsTo(af, {"KingfisherTestApp"});
  }
}

void
KingfisherTestApp::registerApps()
{
  registerApp(KingfisherApp);
  registerApp(KingfisherTestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
KingfisherTestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  KingfisherTestApp::registerAll(f, af, s);
}
extern "C" void
KingfisherTestApp__registerApps()
{
  KingfisherTestApp::registerApps();
}
