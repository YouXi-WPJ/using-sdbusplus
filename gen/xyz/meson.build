# Generated file; do not modify.
subdir('pdi')

sdbusplus_current_path = 'xyz'

generated_markdown += custom_target(
    'xyz/pdi__markdown'.underscorify(),
    input: [ '../../yaml/xyz/pdi.interface.yaml',  ],
    output: [ 'pdi.md' ],
    depend_files: sdbusplusplus_depfiles,
    command: [
        sdbuspp_gen_meson_prog, '--command', 'markdown',
        '--output', meson.current_build_dir(),
        '--tool', sdbusplusplus_prog,
        '--directory', meson.current_source_dir() / '../../yaml',
        'xyz/pdi',
    ],
    install: should_generate_markdown,
    install_dir: [inst_markdown_dir / sdbusplus_current_path],
    build_by_default: should_generate_markdown,
)

