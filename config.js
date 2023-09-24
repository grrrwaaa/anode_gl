const assert = require("assert"),
fs = require("fs"),
path = require("path");

/*
    Basic idea here is that we have a configuration defined in a JSON file


*/

function Config(filepath, config={}) {

    let lasttime

    function load() {
        lasttime = fs.statSync(filepath).mtimeMs
        try {
            Object.assign(config, JSON.parse(fs.readFileSync(filepath)))

            console.log("reloaded", filepath)
        } catch (e) {
            console.error("JSON ERROR", e)
        }
    }

    load()

    // now also watch the file:
    let watcher = fs.watch(filepath, (eventType, filename) => {
        if (fs.statSync(filepath).mtimeMs > lasttime) load()
    })

    return config
}

module.exports = Config