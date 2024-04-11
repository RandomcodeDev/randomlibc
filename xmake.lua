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
    add_cxflags("-Zl")
    add_arflags("-nodefaultlib")
    add_ldflags("-nodefaultlib")
elseif clang then
    add_cxflags("-ffreestanding")
    add_ldflags("-nostdlib")
end

target("mimalloc")
    set_kind("static")

    add_headerfiles(path.join("deps", "mimalloc", "include", "**.h"))
    add_files(
        path.join("deps", "mimalloc", "src", "alloc.c"),
        path.join("deps", "mimalloc", "src", "alloc-aligned.c"),
        path.join("deps", "mimalloc", "src", "alloc-posix.c"),
        path.join("deps", "mimalloc", "src", "arena.c"),
        path.join("deps", "mimalloc", "src", "bitmap.c"),
        path.join("deps", "mimalloc", "src", "heap.c"),
        path.join("deps", "mimalloc", "src", "init.c"),
        path.join("deps", "mimalloc", "src", "options.c"),
        path.join("deps", "mimalloc", "src", "os.c"),
        path.join("deps", "mimalloc", "src", "page.c"),
        path.join("deps", "mimalloc", "src", "random.c"),
        path.join("deps", "mimalloc", "src", "segment.c"),
        path.join("deps", "mimalloc", "src", "segment-map.c"),
        path.join("deps", "mimalloc", "src", "stats.c"),
        path.join("deps", "mimalloc", "src", "prim", "prim.c")
    )

    if is_plat("windows") then
        add_files(path.join("deps", "mimalloc", "src", "prim", "windows", "*.c"))
    elseif is_plat("macos") then
        add_files(path.join("deps", "mimalloc", "src", "prim", "osx", "*.c"))
    else
        add_files(path.join("deps", "mimalloc", "src", "prim", "unix", "*.c"))
    end

    if is_mode("debug") then
        add_defines("MI_DEBUG=3", "MI_SECURE=4")
    end

    add_defines("_IN_LIBC=1", "_CORECRT_BUILD=1", "CRTDLL=1", "_CRTBLD=1")

    set_warnings("none")

    add_includedirs(path.join("deps", "mimalloc", "include"))

    add_forceincludes("stdio.h")
target_end()

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
        path.join("libc", "errno", "*.c"),
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

    add_defines("_IN_LIBC=1", "_CORECRT_BUILD=1", "CRTDLL=1", "_CRTBLD=1")

    add_includedirs(
        path.join("libc", "include"),
        path.join("deps", "mimalloc", "include")
    )

    add_deps("mimalloc")
target_end()

target("test")
    set_kind("binary")
    add_files(path.join("test", "test.c"))

    add_deps("crt0", "libc", {inherit = false})
target_end()

