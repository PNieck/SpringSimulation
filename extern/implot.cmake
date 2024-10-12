# Check if subrepo was downloaded
if(NOT EXISTS "${PROJECT_SOURCE_DIR}/extern/implot/implot.h")
    message(
            FATAL_ERROR
            "The submodules were not downloaded! GIT_SUBMODULE was turned off or failed. Please update submodules and try again."
    )
endif()


add_library(
    implot
    STATIC
    implot/implot.h
    implot/implot_internal.h
    implot/implot.cpp
    implot/implot_items.cpp

    # Optional file with demo plots
    implot/implot_demo.cpp
)

target_link_libraries(implot imgui)
target_include_directories(implot PUBLIC implot/)
