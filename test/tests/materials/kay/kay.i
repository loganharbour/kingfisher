[Mesh]
  type = GeneratedMesh
  dim = 2
  nx = 10
  ny = 10
[]

[Variables]
  [u]
  []
[]

[Kernels]
  [diff]
    type = ADMatDiffusion
    variable = u
    diffusivity = k
  []
  [reaction]
    type = ADMatReaction
    variable = u
    reaction_rate = 1
  []
[]

[BCs]
  [neumann]
    type = ADNeumannBC
    boundary = 'top right bottom left'
    variable = u
    value = 0.2
  []
[]

[Materials]
  [k]
    type = KayMaterial
    variable = u
  []
[]

[Executioner]
  type = Steady
  solve_type = NEWTON
  petsc_options_iname = '-pc_type -pc_hypre_type'
  petsc_options_value = 'hypre boomeramg'
[]

[Outputs]
  exodus = true
[]
