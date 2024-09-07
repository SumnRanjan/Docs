const path = require('path')

const myPath = 'C:/Users/suman/Web Development/JavaScript/varible.js'

const pathInfo = {
    filename : path.basename(myPath),
    foldername : path.dirname(myPath),
    fileExt : path.extname(myPath),
    absornot : path.isAbsolute(myPath),
    detail : path.parse(myPath),
}

console.log(pathInfo)

console.log(path.join('Folder1' , 'Folder2' , 'Folder3' , 'file.txt')) // it give relative path
console.log(path.resolve('Folder1' , 'Folder2' , 'Folder3' , 'file.txt')) // it give absloute path
