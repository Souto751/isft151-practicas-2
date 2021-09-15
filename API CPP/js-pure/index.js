fetch('http://192.168.44.128/api/main.bin',
{
    method: 'GET',
    mode: 'cors',
    headers: {
        'Content-Type': 'application/json'
    }
}).then(
    function(res){
        if(res.status !== 200){
            let error = 'Error: ' + res.status;
            document.getElementById('info').innerHTML = error;
            console.log(error);
        }

        res.json().then(data => {
            document.getElementById('info').innerHTML = data;
            console.log(data)
        })
    }
).catch(err => {
    document.getElementById('info').innerHTML = err;
    console.log(err);
})