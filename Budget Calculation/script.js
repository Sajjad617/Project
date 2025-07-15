
function SubmitForm() {

      Swal.fire({
  icon: "error",
  title: "Oops...",
  text: "Something went wrong!",
  footer: '<a href="#">Why do I have this issue?</a>'
});
}




function Check() {





    const total_budget = parseInt(document.getElementById("total_budget").value);
    const num = document.getElementsByName("name");
    var check = document.getElementsByTagName("input") // Error when check foreach loop conditon can not work
    // for(var i=0;i<= check.length;i++){
    //     if( check[i].value ===''){
    //         alert("Every box need fillup");
    //         return 0;
    //     }
    // }

    var asolArray = Array.from(check);
    // debugger;
    for (var x of asolArray) {
        if (x.value === "") {


            alert("Every box need fillup");
            return;

        }
    }
    // asolArray.forEach((x)=>{

    // });

    const Internetbill = document.getElementById("internet_bill").value;
    if (Internetbill > 500) {
        alert("Internet Bill Greater than 500 is no eligable");
        return;
    }
    let sum = 0;

    for (let i = 0; i < num.length; i++) {
        sum += parseInt(num[i].value);
    }
    // alert(total_budget+50);

    if (total_budget == sum)
        alert("Budget is okhay");
    else
        alert("Budget is not okhay");

    // alert(sum);
    return;
}
function checkbill() {
    debugger
    let val = document.getElementById("internet_bill").value;
    if (parseInt(val) > 500) {

        document.getElementById("internetValidation").innerText = "Internet Bill Greater than 500 is no eligable";

        // alert("Internet Bill Greater than 500 is no eligable");
        return;
    }

}