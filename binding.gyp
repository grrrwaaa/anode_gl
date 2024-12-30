{
  "targets": [
    {
      "target_name": "gles3",
      "sources": [ "src/node-gles3.cpp" ],
      'include_dirs': [
        'src', 'src/include'
      ],
      'cflags':[],
      'conditions': [
        ['OS=="mac"',
          {
            'include_dirs': [
              '/opt/homebrew/Cellar/glew/2.2.0_1/include',
              '/opt/homebrew/Cellar/glfw/3.3.9/include'
            ],
            'library_dirs': [
              '/opt/homebrew/Cellar/GLEW/2.2.0_1/lib',
              '/opt/homebrew/Cellar/glfw/3.3.9/lib'
            ],
            'libraries': [
              '-lGLEW',
              '-framework OpenGL'
            ],
            'xcode_settings': {
              'MACOSX_DEPLOYMENT_TARGET': '10.13',
              'OTHER_CFLAGS': [
                "-Wno-unused-but-set-variable","-Wno-unused-parameter","-Wno-unused-variable","-Wno-int-to-void-pointer-cast"
              ],
            }
          }
        ],
        ['OS=="linux"', {
          'libraries': [
            '-lGLEW','-lGL']
          }
        ],
        ['OS=="win"',
          {
            'include_dirs': [
              './node_modules/native-graphics-deps/include',
              ],
            'library_dirs': [
              './node_modules/native-graphics-deps/lib/windows/glew',
              'lib/<(target_arch)',
              ],
            'libraries': [
              'glew32.lib',
              'opengl32.lib'
              ],
            'defines' : [
              'WIN32_LEAN_AND_MEAN',
              'VC_EXTRALEAN'
            ],
            'msvs_settings' : {
              'VCCLCompilerTool' : {
                'AdditionalOptions' : []
              },
              'VCLinkerTool' : {
                'AdditionalOptions' : ['/OPT:REF','/OPT:ICF','/LTCG']
              },
            },
            'copies': [
              {
                'destination': './build/<(CONFIGURATION_NAME)/',
                'files': [
                  './node_modules/native-graphics-deps/lib/windows/glew/glew32.dll'
                 ]
              }
            ],
          }
        ],
      ],
    },
    {
      "target_name": "glfw3",
      "sources": [ "src/node-glfw3.cpp" ],
      'include_dirs': [
        'src', 'src/include'
      ],
      'cflags':[],
      'conditions': [
        ['OS=="mac"',
          {
            'include_dirs': [
              '/opt/homebrew/Cellar/glfw/3.3.9/include'
            ],
            'library_dirs': [
              '/opt/homebrew/Cellar/glfw/3.3.9/lib'
            ],
            'libraries': [
              '-framework Cocoa',
              '-lglfw'
            ],
            'xcode_settings': {
              'MACOSX_DEPLOYMENT_TARGET': '10.13',
              'OTHER_CFLAGS': [
                "-Wno-unused-but-set-variable","-Wno-unused-parameter","-Wno-unused-variable"
              ],
            }
          }
        ],
        ['OS=="linux"', {
          'libraries': []
          }
        ],
        ['OS=="win"',
          {
            'include_dirs': [
              './node_modules/native-graphics-deps/include',
              ],
            'library_dirs': [
              './node_modules/native-graphics-deps/lib/windows/glfw'
              ],
            'libraries': [
              'glfw3dll.lib'
            ],
            'defines' : [
              'WIN32_LEAN_AND_MEAN',
              'VC_EXTRALEAN'
            ],
            'msvs_settings' : {
              'VCCLCompilerTool' : {
                'AdditionalOptions' : []
              },
              'VCLinkerTool' : {
                'AdditionalOptions' : ['/OPT:REF','/OPT:ICF','/LTCG']
              },
            },
            'copies': [
              {
                'destination': './build/<(CONFIGURATION_NAME)/',
                'files': [
                  './node_modules/native-graphics-deps/lib/windows/glfw/glfw3.dll'
                 ]
              }
            ],
          }
        ],
      ],
    },
    
  ]
}