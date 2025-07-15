function Check() {
    debugger
    let re = 0;
    const len = document.getElementsByTagName("input");

    if(document.getElementById("Infinite_loop").checked)
    {
        re++;
    }
    if(document.getElementById("Sorted").checked)
    {
        re++;
    }
    if(document.getElementById("Merge").checked)
    {
        re++;
    }
    if(document.getElementById("Stack").checked)
    {
        re++;
    }
    if(document.getElementById("Map").checked)
    {
        re++;
    }
    
    // alert(re);

    alert(`Your Mark is ${re} / ${len.length/4}`);

    // debugger

    // var arr = document.getElementsByName("box1") ;
    // var ele = Array.from(arr);
    // let re = 0;

    // for (i = 0; i < ele.length; i++) 
    // {
    //         if (ele[i].checked)
    //             alert(ele[i].value)

    // }
    //     alert(ele[i].value)
    // }
    // for (i = 0; i < ele.length; i++) {
    //     // if (ele[i].type = "radio") {
    //     alert(ele[i]);
    //     if (ele[i].checked)
    //             // document.getElementById("result").innerHTML+= ele[i].name + " Value: "+ ele[i].value + "<br>";
    // }
    // alert(re)
    // alert(ele.length);

    // debugger
    // const answer = {
    //     Infinite_loop: "Infinite_loop",
    //     Sorted: "Sorted",
    //     Merge: "Merge",
    //     Stack: "Stack",
    //     58: "58"
    // }
    // // const answer = ["Infinite_loop", "Sorted", "Merge", "Stack", "58"]
    // let res = 0

    // let len = Object.keys(answer).length;

    // for (let ans in answer) {
    //     const selected = document.querySelector(`input[id="${ans}"]:checked`);
    //     if (selected && selected.value.toLowerCase() == correctanswer[question].toLowerCase()) {
    //         res++;
    //     }
    // }

    //  alert(`Your Score is ${score} / ${total}`);
    // alert(len)
    // const arr = Array.from(answer)
    // for(x of answer)
    // {
    //     // alert("hel")
    //     alert(x);
    // }
}