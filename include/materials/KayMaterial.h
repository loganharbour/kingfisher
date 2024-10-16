#pragma once

#include "ADMaterial.h"

class KayMaterial : public ADMaterial
{
public:
  static InputParameters validParams();

  KayMaterial(const InputParameters & parameters);

protected:
  /// Necessary override. This is where the values of the properties are computed.
  virtual void computeQpProperties() override;

  /// The coupled variable gradient
  const ADVariableGradient & _grad_u;

  /// The k material property
  ADMaterialProperty<Real> & _k;
};
