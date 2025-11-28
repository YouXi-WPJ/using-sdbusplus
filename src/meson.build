executable(
    'using-sdbusplus',
    get_option('using-yaml') ? generated_sources : [],
    'main.cpp',
    get_option('using-yaml') ? 'pdi.cpp' : [],
    include_directories: include_directories('../gen'),
    dependencies: [systemd_dep, sdbusplus_dep]
    + (get_option('using-boost') ? [boost_dep] : []),
    install: true,
)