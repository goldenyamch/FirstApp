#include "FirstAppTestApp.h"
#include "FirstAppApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"

template <>
InputParameters
validParams<FirstAppTestApp>()
{
  InputParameters params = validParams<FirstAppApp>();
  return params;
}

FirstAppTestApp::FirstAppTestApp(InputParameters parameters) : MooseApp(parameters)
{
  Moose::registerObjects(_factory);
  FirstAppApp::registerObjectDepends(_factory);
  FirstAppApp::registerObjects(_factory);

  Moose::associateSyntax(_syntax, _action_factory);
  FirstAppApp::associateSyntaxDepends(_syntax, _action_factory);
  FirstAppApp::associateSyntax(_syntax, _action_factory);

  bool use_test_objs = getParam<bool>("allow_test_objects");
  if (use_test_objs)
  {
    FirstAppTestApp::registerObjects(_factory);
    FirstAppTestApp::associateSyntax(_syntax, _action_factory);
  }
}

FirstAppTestApp::~FirstAppTestApp() {}

// External entry point for dynamic application loading
extern "C" void
FirstAppTestApp__registerApps()
{
  FirstAppTestApp::registerApps();
}
void
FirstAppTestApp::registerApps()
{
  registerApp(FirstAppApp);
  registerApp(FirstAppTestApp);
}

// External entry point for dynamic object registration
extern "C" void
FirstAppTestApp__registerObjects(Factory & factory)
{
  FirstAppTestApp::registerObjects(factory);
}
void
FirstAppTestApp::registerObjects(Factory & /*factory*/)
{
}

// External entry point for dynamic syntax association
extern "C" void
FirstAppTestApp__associateSyntax(Syntax & syntax, ActionFactory & action_factory)
{
  FirstAppTestApp::associateSyntax(syntax, action_factory);
}
void
FirstAppTestApp::associateSyntax(Syntax & /*syntax*/, ActionFactory & /*action_factory*/)
{
}
