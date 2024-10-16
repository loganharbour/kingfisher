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
};
