project('codejam', 'cpp',
  default_options : [
      'cpp_std=c++14',
      'warning_level=3'
    ],
  meson_version : '>=0.45.0' )

project_description = 'My Google CodeJam Playground'

gtest_dep   = dependency('gtest', main : true, required : false)

inc = include_directories('include')

# past competitions

# subdir('2019/Qualification')
# subdir('2019/Round1C')
# subdir('2019/Round3')

# subdir('2020/Qualification')
# subdir('2020/Round1B')
# subdir('2020/Round1C')

# template for upcoming competitions
subdir('template')
