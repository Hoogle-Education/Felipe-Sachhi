export function Noticia({title, author, content}) {
  return (
    <div>
      <h1>{title}</h1>
      <h2>{author}</h2>
      <article>{content}</article>
    </div>
  )
}