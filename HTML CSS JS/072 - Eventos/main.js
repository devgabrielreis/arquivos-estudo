const myBox = document.getElementById("box");
const myBoxes = document.querySelectorAll(".box");

myBox.addEventListener("mouseover", function(){
    for(let i = 0; i < myBoxes.length; i++)
    {
        myBoxes[i].style.backgroundColor = "black";
    }
});

window.addEventListener("scroll", function(){
    console.log(scrollY);
});
