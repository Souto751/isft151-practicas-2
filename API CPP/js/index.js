const express = require('express');
const fetch = (...args) => import('node-fetch').then(({default: fetch}) => fetch(...args));

const app = express();
const port = 3000;
const host = 'localhost';

app.get('/', async (req, response) => {
    await fetch('http://192.168.44.128/api/main.bin', {method: 'GET'}).then(res => res.json()).then(res => response.send(res));
});

app.listen(port, host, () => {
    console.log('Servidor en linea');
})