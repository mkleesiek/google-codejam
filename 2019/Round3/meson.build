# prepare and build executables
foreach appname : ['A', 'B', 'C', 'D']
    exe = executable(appname, appname + '.cpp',
        include_directories : inc,
        install : true,
        install_dir : meson.current_source_dir()
    )
endforeach

# compile unit tests
if gtest_dep.found()
    foreach appname : ['A', 'B', 'C', 'D']
        exe = executable(appname + '-test', appname + '-test.cpp',
            include_directories : inc,
            dependencies : [gtest_dep]
        )
        test(appname + '-test', exe)
    endforeach
endif
