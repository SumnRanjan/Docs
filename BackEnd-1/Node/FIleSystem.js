const fs = require('fs')

//Create Directory --
// fs.mkdir('./myFolder', (err) => {
//     if (err) console.log(err)
//     else console.log("Folder Created ")
// })

//Write data into file
// const data = "Hey This is Write files data."
// fs.writeFile("./myFolder/fife.txt", data, (err) => {
//     if (err) console.log(err)
//         else console.log("Written into File ")
// })

// const data = "This is new data"

//Append File 
// const data = "new data"
// fs.appendFile("./myFolder/fife.txt" , data , (err)=>{
//     if (err) console.log(err)
//         else console.log("Append into File ")
// })


//case - 2
// const data = " Hey This is Write files data."
// fs.writeFile("./myFolder/fife.txt", data, {flag : 'a'},(err) => {
//     if (err) console.log(err)
//         else console.log("Written into File ")
// })

//Rename
// fs.rename("./sumn.txt", "./xyz.txt", (err) => {
//     if (err) console.log(err)
//     else console.log("File Rename")
// })


//Copy File
// fs.copyFile('./xyz.txt', './myFolder/xyz.txt', (err) => {
//     if (err) console.log(err)
//     else console.log("File copied")
// })

//delete file - unlink
// fs.unlink('./xyz.txt', (err) => {
//     if (err) console.log(err)
//     else console.log("File Deleted")
// })


//Read Dir 
// fs.readdir('./', (err, files) => {
//     if (err) console.log(err)
//     else {
//         console.log("Here Are the file")
//         console.log(files)
//     }
// })

//Remove dir - only Delete empty folder
// fs.rmdir('./abc', (err) => {
//     if (err) console.log(err)
//     else console.log("Folder Deleted :)")
// })

//Remove dir -  Delete full folder
//case 1 - rmdir - it will remove by node in future
// fs.rmdir('./abc',{recursive : true} ,(err) => {
//     if (err) console.log(err)
//     else console.log("Folder Deleted :)")
// })

//case2 - rm
// fs.rm('./abc',{recursive : true} ,(err) => {
//     if (err) console.log(err)
//     else console.log("Folder Deleted :)")
// })


//Read File 
// fs.readFile('./xyz.txt', 'utf-8', (err, data) => {
//     if (err) console.log(err)
//     else {
//         console.log("Here is the data")
//         console.log(data)
//     }
// })
