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

#  yaml option
should_generate_cpp = get_option('using-yaml')
should_generate_markdown = get_option('using-yaml')
# yaml subdirectories
yaml_selected_subdirs = ['xyz']

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
if get_option('using-yaml')
    add_project_arguments('-DUSE_YAML', language: 'cpp')
    message('Enable YAML generation API')
    subdir('gen')
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