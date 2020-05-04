module.exports = grunt => {
    grunt.initConfig({
       

        exec: {
            build: "X:/Projects/emscriptenSDK/emsdk/emsdk_env.bat & echo Building... & emcc main.cpp -O2 -s USE_SDL=2 -s USE_SDL_IMAGE=2 -s SDL2_IMAGE_FORMATS=[\"png\"] --preload-file assets -o index.js -s LLD_REPORT_UNDEFINED"
        },

        watch: {
            cpp: {
                files: ["**/*.cpp", "**/*.h"],
                tasks: ["exec:build"]
            },
        }
    })
    grunt.loadNpmTasks("grunt-contrib-watch")
    grunt.loadNpmTasks('grunt-contrib-concat')
    grunt.loadNpmTasks('grunt-contrib-uglify-es')
    grunt.loadNpmTasks("grunt-exec")

    grunt.registerTask("default", ["watch"])
}