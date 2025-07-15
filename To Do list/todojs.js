function addTask() {
    const taskInput = document.getElementById("textbox");
    const taskText = taskInput.value.trim();

    if(taskText === "")
    {
        alert("Please Write Some");
        return;
    }

    const li = document.createElement("li");
    li.innerText = taskText;

    const delBtn = document.createElement("button");
    delBtn.innerText = "Remove";
    delBtn.className = "delete-btn";
    delBtn.onclick = function() {
        li.remove();
    };

    li.appendChild(delBtn);
    document.getElementById("taskList").appendChild(li);

    textbox.value= "";
}