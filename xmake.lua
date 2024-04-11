add_rules("mode.debug", "mode.release", "plugin.vsxmake.autoupdate")

set_policy("check.auto_ignore_flags", false)

set_project("randomlibc")
set_version("0.0.0", {build = "%Y%m%d%H%M"})

add_includedirs("include")

if is_plat("windows") then
    add_includedirs(path.join("deps", "phnt", "include"))
end

if get_config("toolchain") == "msvc" then
    msvc = true
    clang = false
elseif get_config("toolchain") == "clang-cl" then
    msvc = true
    clang = true
else
    msvc = false
    clang = true -- assume close enough to Clang
end

if msvc then
    add_ldflags("-nodefaultlib")
elseif clang then
    add_cxflags("-ffreestanding")
    add_ldflags("-nostdlib")
end

target("crt0")
    set_kind("static")
    add_headerfiles(path.join("crt0", "*.h"))
    --add_files(path.join("crt0", "*.c"))
    if is_plat("windows") then
        add_files(path.join("crt0", "win32", "start.c"))
    elseif is_plat("linux") then
        if is_arch("x86_64") then
            add_files(path.join("crt0", "linux", "x86_64", "start.asm"))
        end
    end

    add_includedirs(path.join("libc", "include"))
target_end()

target("libc")
    set_kind("shared")
    add_headerfiles(path.join("include", "**.h"), path.join("libc", "include", "**.h"))
    add_files(
        path.join("libc", "startup", "*.c"),
        path.join("libc", "stdlib", "*.c"),
        path.join("libc", "string", "*.c"),
        path.join("libc", "wchar", "*.c"),
        path.join("libc", "wctype", "*.c")
    )

    if is_plat("windows") then
        add_files(path.join("libc", "win32", "**.c"))
    end

    set_prefixname("")

    add_defines("_IN_LIBC=1")
    add_includedirs(path.join("libc", "include"))
target_end()

target("test")
    set_kind("binary")
    add_files(path.join("test", "test.c"))

    add_deps("crt0", "libc")
target_end()

