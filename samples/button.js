button = document.querySelector(".testButton");
button2 = document.querySelector(".testButton2");
output = document.querySelector(".textOutput");

const alertFunction = () => alert("alerta!");

button.addEventListener("click", (event) => {
  event.preventDefault();
  output.textContent += " mais texto";
});

button2.addEventListener("click", function (event) {
  event.preventDefault();
  output.textContent += " mais texto";
});

button2.addEventListener("click", () => {
  alertFunction();
});
