const https = require("https");
const timout = 1000;
const ok = () => console.log("ok");

// setTimeout(ok, 2000);
let interval = setInterval(ok, timout);

setTimeout(() => clearInterval(interval), 4000);
