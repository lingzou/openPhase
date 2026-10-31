//* This file is part of the MOOSE framework
//* https://mooseframework.inl.gov
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "openPhaseTestApp.h"
#include "openPhaseApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"

InputParameters
openPhaseTestApp::validParams()
{
  InputParameters params = openPhaseApp::validParams();
  params.set<bool>("use_legacy_material_output") = false;
  params.set<bool>("use_legacy_initial_residual_evaluation_behavior") = false;
  return params;
}

openPhaseTestApp::openPhaseTestApp(const InputParameters & parameters) : MooseApp(parameters)
{
  openPhaseTestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

openPhaseTestApp::~openPhaseTestApp() {}

void
openPhaseTestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  openPhaseApp::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"openPhaseTestApp"});
    Registry::registerActionsTo(af, {"openPhaseTestApp"});
  }
}

void
openPhaseTestApp::registerApps()
{
  registerApp(openPhaseApp);
  registerApp(openPhaseTestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
openPhaseTestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  openPhaseTestApp::registerAll(f, af, s);
}
extern "C" void
openPhaseTestApp__registerApps()
{
  openPhaseTestApp::registerApps();
}
