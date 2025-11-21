# Project Configuration
project(
    'using-sdbusplus',
    'cpp',
    meson_version: '>=1.1.1',
    default_options: [
      'cpp_std=c++23',
      'warning_level=3',
      'werror=true',
    ],
    version: '1.0.0',
)

# Compilation tools
cpp = meson.get_compiler('cpp')

generated_sources = []
generated_others = []

# dependency
# Note:The systemd version needs to be greater than 252.
systemd_dep = dependency('systemd')

# sdbusplus configuration
sdbusplus_dep = dependency('sdbusplus')
sdbusplusplus_prog = find_program('sdbus++', native: true)
sdbuspp_gen_meson_prog = find_program('sdbus++-gen-meson', native: true)
sdbusplusplus_depfiles = files()
if sdbusplus_dep.type_name() == 'internal'
    sdbusplusplus_depfiles = subproject('sdbusplus').get_variable('sdbusplusplus_depfiles')
endif

# Parse the options to determine the features to support.
if get_option('using-pdi')
    add_project_arguments('-DUSE_PDI', language: 'cpp')
    message('Using Phosphor DBus Interfaces')
    pdi_dep = dependency('phosphor-dbus-interfaces')
    if pdi_dep.type_name() == 'internal'
        subproject('phosphor-dbus-interfaces')
    endif
    subdir('gen/xyz')
endif

if get_option('using-boost')
    add_project_arguments('-DUSE_BOOST', language: 'cpp')
    message('Using Boost Libraries')
    boost_dep = dependency('boost')
    if boost_dep.type_name() == 'internal'
        subproject('boost')
    endif
endif

subdir('src')