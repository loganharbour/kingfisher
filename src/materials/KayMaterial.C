#include "KayMaterial.h"

registerMooseObject("KingfisherApp", KayMaterial);

InputParameters
KayMaterial::validParams()
{
  InputParameters params = ADMaterial::validParams();

  return params;
}

KayMaterial::KayMaterial(const InputParameters & parameters)
  : ADMaterial(parameters)
{
}

void
KayMaterial::computeQpProperties()
{
}
