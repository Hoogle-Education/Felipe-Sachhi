import { useState } from "react"

import styles from "./styles.module.css"

export function Noticia({title, author, content, likes}) {

  const [postLikes, setLikes] = useState(likes)

  function handleLikeAction() {
    setLikes(postLikes + 1)
  }

  return (
    <div className={styles.noticia}>
      <h1 className="titulo">{title}</h1>
      <h2 className="author">{author}</h2>
      <article className="content">{content}</article>

      <div className={styles.interactions}>
        <button onClick={handleLikeAction}>like</button>
        <div className={styles.likes}>likes : {postLikes}</div>
      </div>

    </div>
  )
}