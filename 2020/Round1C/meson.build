# prepare and build executables
foreach appname : ['A', 'B', 'C']
    exe = executable(appname, appname + '.cpp',
        include_directories : inc,
        install : true,
        install_dir : meson.current_source_dir()
    )
endforeach

# compile unit tests
if gtest_dep.found()
    foreach testname : ['A-test', 'B-test', 'C-test']
        exe = executable(testname, testname + '.cpp',
            include_directories : inc,
            dependencies : [gtest_dep]
        )
        test(testname, exe)
    endforeach
endif
