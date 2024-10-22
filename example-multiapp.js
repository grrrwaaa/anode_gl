const { gl, glutils, Window } = require("./index.js")

const App = require("./multiapp.js")


// sync on the global Window, not on each window:
Window.syncfps = 60

let apps = []
for(let i=0; i<4; i++) {
    apps.push(new App({
        title: `window${i}`,
        width: 640, height: 480,
        pos: [50 + 650*i, 50]
    }))
}


Window.animate()