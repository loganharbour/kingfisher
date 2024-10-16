[Mesh]
  type = GeneratedMesh
  dim = 2
  nx = 50
  ny = 50
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
    type = ADMatNeumannBC
    boundary = 'top right bottom left'
    boundary_material = 0.2
    variable = u
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
  solve_type = 'PJFNK'
  petsc_options_iname = '-pc_type -pc_hypre_type'
  petsc_options_value = 'hypre boomeramg'
[]

[Outputs]
  exodus = true
[]
