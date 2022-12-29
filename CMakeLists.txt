# CMakeList.txt : fichier projet CMake de niveau supérieur, effectuez une configuration globale
# et incluez les sous-projets ici.
#
cmake_minimum_required (VERSION 3.8)

project ("RCBanque")

set(BOOST_DIR C:/tools/Boost)
#set(BOOST_DIR c:/tools/wxWidgets)

# Incluez les sous-projets.
add_subdirectory ("RCBanque")
add_subdirectory(Boost_JSON)
add_subdirectory(socket)
add_subdirectory(thread)
add_subdirectory(test_wxWidgets)


