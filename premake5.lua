-- premake5.lua

--  Define the build directories for each action
local buildDirs = {
    gmake = "./build/linux",
    gmake2 = "./build/linux",
    xcode4 = "./build/xcode4",
    vs2019 = "./build/vs2005",
    vs2019 = "./build/vs2008",
    vs2019 = "./build/vs2010",
    vs2019 = "./build/vs2012",
    vs2019 = "./build/vs2013",
    vs2019 = "./build/vs2015",
    vs2019 = "./build/vs2017",
    vs2019 = "./build/vs2019",
    vs2022 = "./build/vs2022",
    codeblocks = "./build/codeblocks",
    codelite = "./build/codelite",
    -- Add more targets as needed
}
local buildDir = buildDirs[_ACTION] or "./build/"


workspace "HelloWorld"
    configurations { "debug", "release" }
    location(buildDir)
    

    project "snapp_ink"
        kind "ConsoleApp" --SharedLib ConsoleApp StaticLib
        language "C++"
        targetdir "bin/%{cfg.buildcfg}"  
        location(buildDir)
        includedirs {"/usr/include/opencv4","./src/", "./src/filters/", "./src/filters/color/", "./src/filters/ai/", "./lib/crow/include"}
        buildoptions { "-O2","-std=c++17", "-Wall", "-fopenmp", "-DCROW_ENABLE_SSL", "-DCROW_ENABLE_COMPRESSION"} 
        linkoptions { "-fopenmp"}
        linkoptions { "-lssl", "-lcrypto", "-lz" }
        links {"ssl", "crypto", "z","pthread", "opencv_stitching ","opencv_alphamat ","opencv_aruco ","opencv_barcode ","opencv_bgsegm ","opencv_bioinspired ","opencv_ccalib ","opencv_dnn_objdetect ","opencv_dnn_superres ","opencv_dpm ","opencv_face ","opencv_freetype ","opencv_fuzzy ","opencv_hdf ","opencv_hfs ","opencv_img_hash ","opencv_intensity_transform ","opencv_line_descriptor ","opencv_mcc ","opencv_quality ","opencv_rapid ","opencv_reg ","opencv_rgbd ","opencv_saliency ","opencv_shape ","opencv_stereo ","opencv_structured_light ","opencv_phase_unwrapping ","opencv_superres ","opencv_optflow ","opencv_surface_matching ","opencv_tracking ","opencv_highgui ","opencv_datasets ","opencv_text ","opencv_plot ","opencv_ml ","opencv_videostab ","opencv_videoio ","opencv_viz ","opencv_wechat_qrcode ","opencv_ximgproc ","opencv_video ","opencv_xobjdetect ","opencv_objdetect ","opencv_calib3d ","opencv_imgcodecs ","opencv_features2d ","opencv_dnn ","opencv_flann ","opencv_xphoto ","opencv_photo ","opencv_imgproc ","opencv_core"}


        files ({ "./src/**.hh", "./src/**.hpp", "./src/**.cc", "./src/**.cpp" })
        removefiles({"./test/**"})
 
        filter "configurations:debug" 
            defines { "DEBUG" }
            symbols "On"

        filter "configurations:release"
            defines { "NDEBUG" }
            optimize "On"