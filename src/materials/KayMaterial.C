#include "KayMaterial.h"

registerMooseObject("KingfisherApp", KayMaterial);

InputParameters
KayMaterial::validParams()
{
  InputParameters params = ADMaterial::validParams();
  params.addRequiredCoupledVar("variable", "The variable in the denominator");
  return params;
}

KayMaterial::KayMaterial(const InputParameters & parameters)
  : ADMaterial(parameters),
   _grad_u(adCoupledGradient("variable")),
   _k(declareADProperty<Real>("k"))
{
}

void
KayMaterial::computeQpProperties()
{
  _k[_qp] = 1. / std::sqrt(1. + _grad_u[_qp] * _grad_u[_qp]);
}
