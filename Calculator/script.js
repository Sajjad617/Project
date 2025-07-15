let display = document.getElementById("display");

function appendValue(value) {
  display.value += value;
}

function clearDisplay() {
  display.value = "";
}

function calculateResult() {
  try {
    display.value = eval(display.value);
  } catch {
    display.value = "Error";
  }
}

let isOn = false;

function togglePower() {
  const display = document.getElementById("display");
  const powerBtn = document.getElementById("power-btn");
  const buttons = document.querySelectorAll(".calc-btn");

  isOn = !isOn;

  if (isOn) {
    display.style.backgroundColor = "#fff";
    display.style.color = "#000";
    powerBtn.textContent = "ON";

    buttons.forEach(btn => {
      btn.disabled = false;
      btn.style.opacity = "1";
      btn.style.cursor = "pointer";
    });
  } else {
    display.value = "";
    display.style.backgroundColor = "#333";
    display.style.color = "#555";
    powerBtn.textContent = "OFF";

    buttons.forEach(btn => {
      btn.disabled = true;
      btn.style.opacity = "0.5";
      btn.style.cursor = "not-allowed";
    });
  }
}