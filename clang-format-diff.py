import os

cpp_extensions = (".cpp", ".cxx", ".c++", ".cc", ".cp", ".c", ".i", ".ii", ".h", ".h++", ".hpp", ".hxx", ".hh", ".inl", ".inc", ".ipp", ".ixx", ".txx", ".tpp", ".tcc", ".tpl")

for root, dirs, files in os.walk("src"):
    for file in files:
        if file.endswith(cpp_extensions):
            os.system("clang-format -i -style=file " + root + "/" + file)