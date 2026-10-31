#include "openPhaseApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
openPhaseApp::validParams()
{
  InputParameters params = MooseApp::validParams();
  params.set<bool>("use_legacy_material_output") = false;
  params.set<bool>("use_legacy_initial_residual_evaluation_behavior") = false;
  return params;
}

openPhaseApp::openPhaseApp(const InputParameters & parameters) : MooseApp(parameters)
{
  openPhaseApp::registerAll(_factory, _action_factory, _syntax);
}

openPhaseApp::~openPhaseApp() {}

void
openPhaseApp::registerAll(Factory & f, ActionFactory & af, Syntax & syntax)
{
  ModulesApp::registerAllObjects<openPhaseApp>(f, af, syntax);
  Registry::registerObjectsTo(f, {"openPhaseApp"});
  Registry::registerActionsTo(af, {"openPhaseApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
openPhaseApp::registerApps()
{
  registerApp(openPhaseApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
openPhaseApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  openPhaseApp::registerAll(f, af, s);
}
extern "C" void
openPhaseApp__registerApps()
{
  openPhaseApp::registerApps();
}
