project('codejam', 'cpp',
  version : '0.3.1',
  default_options : [
      'cpp_std=c++14',
      'warning_level=3'
    ],
  meson_version : '>=0.45.0' )

project_description = 'My Google CodeJam Playground'

gtest_dep   = dependency('gtest', main : true, required : false)

inc = include_directories('include')

subdir('2019')
subdir('2020')
