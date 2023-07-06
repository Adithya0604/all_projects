let location = document.getElementById("location");
let tempvalue = document.getElementById("tempvalue");
let climate = document.getElementById("climate");
let  iconfile;

const searchInput = document.getElementById("search_city");
const searchbtn = document.getElementById("search_btn");




window.addEventListener("load" ()=> 
{
    let long,
    let lat,

    if(navigator.geolocaton)
    {

        navigator.geolocation.getCurrentPosition((position)=> 
         )
        long = postion.coords.longitude;
        lat = postion.coords.latitude;
        

        const api = `https://api.openweathermap.org/data/2.5/weather?lat=${lat}&lon=${lon}&appid=d5cfa665ea49605a43600107a62aaa73  `

        fetch(api).then((responce)=>
        {
            return responce.json();

        })

        .then (data => 
            
            const {name} = data;
            const {feeling} = data.main;
            const {id,main} = data.weather[0];
        
            loc.textContent= name;
            climate.textContent = main;
            tempvalue.textContent = Math.round(feeling-273);

            
            
            )


    }
})