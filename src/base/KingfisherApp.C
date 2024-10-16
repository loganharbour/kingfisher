#include "KingfisherApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
KingfisherApp::validParams()
{
  InputParameters params = MooseApp::validParams();
  params.set<bool>("use_legacy_material_output") = false;
  params.set<bool>("use_legacy_initial_residual_evaluation_behavior") = false;
  return params;
}

KingfisherApp::KingfisherApp(InputParameters parameters) : MooseApp(parameters)
{
  KingfisherApp::registerAll(_factory, _action_factory, _syntax);
}

KingfisherApp::~KingfisherApp() {}

void
KingfisherApp::registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  ModulesApp::registerAllObjects<KingfisherApp>(f, af, s);
  Registry::registerObjectsTo(f, {"KingfisherApp"});
  Registry::registerActionsTo(af, {"KingfisherApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
KingfisherApp::registerApps()
{
  registerApp(KingfisherApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
KingfisherApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  KingfisherApp::registerAll(f, af, s);
}
extern "C" void
KingfisherApp__registerApps()
{
  KingfisherApp::registerApps();
}
