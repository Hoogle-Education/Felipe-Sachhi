import { useEffect, useState } from "react"
import { Noticia } from "./components/Noticia"
import axios from 'axios'

import "./global.css"
import styles from "./App.module.css"

export function App() {

  const [noticias, setNoticias] = useState([])

  async function loadNoticias() {
     const json = await axios.get('http://localhost:3333/posts')
       .then(reponse => reponse.data)

     setNoticias(json)
  }

  useEffect(() => {
    loadNoticias()
  }, [])

  return (
    <>
      {noticias.map(({title, author, content, likes}, index) => {
        return (
          <Noticia
            key={index} 
            author={author} 
            title={title} 
            content={content} 
            likes={likes} 
          />
        )
      })}
    </>
  )
}