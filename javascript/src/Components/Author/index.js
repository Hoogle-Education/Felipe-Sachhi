class Author extends HTMLElement {
  constructor() {
    super();

    const shadow = this.attachShadow({ mode: "open" });
    shadow.appendChild(this.build());
    shadow.appendChild(this.styles());
  }

  build() {
    const componentRoot = document.createElement("div");
    componentRoot.setAttribute("class", "author");

    const nameComponent = document.createElement("span");
    nameComponent.setAttribute("class", "name");
    nameComponent.textContent = this.getAttribute("name");

    const usernameComponent = document.createElement("span");
    usernameComponent.setAttribute("class", "username");
    usernameComponent.textContent = "@" + this.getAttribute("username");

    componentRoot.appendChild(nameComponent);
    componentRoot.appendChild(usernameComponent);

    return componentRoot;
  }

  styles() {
    const style = document.createElement("style");
    style.textContent = `
      .author {
        border: 3px solid blue;
        color: blue;
        display: flex;
      }

      .author {
        font-weight: bold;
      }

      .username {
        opacity: 70%;
      }

      span > span {
        margin-right: 0.25em;
      }
    `;

    return style;
  }
}

console.log(customElements);
customElements.define("author-card", Author);
/* <div class="author">
<span class="name">Joao Pedro</span>
<span class="username"> @jp123_pedro </span>
</div> */
