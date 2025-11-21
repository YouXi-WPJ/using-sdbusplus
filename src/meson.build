executable(
    'using-sdbusplus',
    generated_sources,
    'main.cpp',
    get_option('using-pdi') ? 'pdi.cpp' : [],
    include_directories: include_directories('../gen'),
    dependencies: [systemd_dep, sdbusplus_dep]
    + (get_option('using-pdi') ? [pdi_dep] : [])
    + (get_option('using-boost') ? [boost_dep] : []),
    install: true,
)